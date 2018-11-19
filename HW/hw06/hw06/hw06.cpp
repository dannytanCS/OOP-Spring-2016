//
//  main.cpp
//  hw06
//
//  Created by Danny Tan on 3/20/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//prototype
class Lord;

//Protector class
class Protector {
public:
    //constructor for Protector
    Protector (const string& someName, int someStr) : dead(false), lordPtr (nullptr), name(someName), str(someStr) {}
    //abstract class, makes sure derived class can defend
    virtual void defend() const = 0;
    //gets the strength of the protector
    int getStr() const {
        return str;
    }
    //sets the strength of the protector
    void setStr(int someStr){
        str = someStr;
    }
    //gets the name of the protector
    string getName() const {
        return name;
    }
    //gets the lord of the protector
    Lord* getLord() const {
        return lordPtr;
    }
    //sets a lord to the protector
    void setLord(Lord* someLord) {
        lordPtr = someLord;
    }
    //check if protector is dead
    bool isDead()const {
        return dead;
    }
    //sets Protector to death
    void setDeath(){
        dead = true;
    }
private:
    bool dead;
    Lord* lordPtr;
    string name;
    int str;
};

//Noble class
class Noble {
public:
    //constructor of noble
    Noble (string someName) : dead(false) , name(someName) {}
    //gets the name for the noble
    string getName() const {
        return name;
    }
    //battle for noble
    virtual void battle(Noble& someNoble) {
        cout << getName() << " battles " << someNoble.getName() << endl;
        //checks if either of the nobles are dead
        if (isHeDead() == false){
            if (someNoble.isHeDead() == false) {
                //calls for their army's defend method if the noble has an army
                battleCry();
                someNoble.battleCry();
                //checks the total strength of each noble and determine who is the winner
                if (totalStr()> someNoble.totalStr()) {
                    cout << getName() << " defeats " << someNoble.getName() << endl;
                    changeStr(1-(someNoble.totalStr()/totalStr()));
                    someNoble.changeStr(0);
                    someNoble.setDeath();
                }
                else if (totalStr() < someNoble.totalStr()) {
                    cout << someNoble.getName() << " defeats " << getName() << endl;
                    someNoble.changeStr(1-(totalStr()/someNoble.totalStr()));
                    changeStr(0);
                    setDeath();
                }
                else {
                    cout << "Mutual Annilation: " << getName() << " and " << someNoble.getName() <<  " die at each other's hands" << endl;
                    changeStr(0);
                    someNoble.changeStr(0);
                    setDeath();
                    someNoble.setDeath();
                }
            }
            else {
                cout << "He is dead, " << getName() << endl;
            }
        }
        else {
            if (someNoble.isHeDead() == false) {
                cout << "He is dead, " << someNoble.getName() << endl;
            }
            else {
                cout << "Oh, NO! They're both dead! Yuck!" << endl;
            }
        }
    }
    //checks if noble is dead
    bool isHeDead() const {
        return dead;
    }
    //sets the death of the noble
    void setDeath(){
        dead = true;
    }
    //abstract class, makes sure derived class can do these
    //calls defend method for the army if it has
    virtual void battleCry() const = 0;
    //changes the strength of the army
    virtual void changeStr(float multiplier) = 0;
    //finds the total strength of the army
    virtual float totalStr() const = 0;
    
private:
    bool dead;
    string name;
};
//Lord Class inheriting from Noble
class Lord : public Noble {
public:
    //Lord constructor
    Lord (const string& someName) : Noble(someName){}
    //hires protector
    void hires(Protector& someProtector){
        //checks if the protector or noble is dead
        if (isHeDead() == false){
            if (someProtector.isDead() == false){
                if (someProtector.getLord() == nullptr){
                    army.push_back(&someProtector);
                    someProtector.setLord(this);
                }
                else {
                    cout << someProtector.getName() << " is already hired" << endl;
                }
            }
            else {
                cout << someProtector.getName() << " is dead. Cannot be hired " << endl;
            }
        }
        else{
            cout << getName() << " is dead. Cannot hire protector. " << endl;
        }
    }
    //calls the defend method for each protector
    virtual void battleCry() const {
        for (Protector* protector: army){
            protector -> defend();
        }
    }
    //changes the strength of the army
    virtual void changeStr(float multiplier) {
        for (Protector* protector: army){
            protector -> setStr((protector -> getStr())* multiplier);

        }
    }
    //finds the total strength of the army
    virtual float totalStr() const {
        float str = 0;
        for (Protector* protector: army){
            str += protector -> getStr();
        }
        return str;
    }
private:
    vector <Protector*> army;
};

//Noble that has the strength to fight
class PersonWithStrengthToFight : public Noble {
public:
    //Constructor for noble with strength to fight
    PersonWithStrengthToFight (const string& someName, int someStr) : Noble (someName), str(someStr) {}
    //battleCry doesn't do anything because it has no army
    virtual void battleCry() const {};
    //changes the strength of the noble
    virtual void changeStr(float multiplier) {
        str *= multiplier;
    }
    //finds the total strength of the noble
    virtual float totalStr() const {
        return str;
    }
private:
    float str;
};
//wizard inherit from protector
class Wizard : public Protector {
public:
    //wizard constructor
    Wizard (const string& someName, int someStr) : Protector (someName, someStr) {}
    //its own defend method
    virtual void defend() const {
        cout << "POOF" << endl;
    }
private:
};
//warrior inherit from protector
class Warrior : public Protector {
public:
    Warrior (const string& someName, int someStr) : Protector (someName, someStr) {}
private:
};
//Archer inherit from warrior
class Archer : public Warrior {
public:
    Archer (const string& someName, int someStr) : Warrior (someName, someStr) {}
    //its own defend method
    virtual void defend() const {
        cout << "TWANG!" << getName() << " says: Take that in the name of my lord," << getLord() -> getName() << endl;
    }
private:
};
//swordsman inherit from warrior
class Swordsman : public Warrior {
public:
    Swordsman (const string& someName, int someStr) : Warrior (someName, someStr) {}
    //its own defend method
    virtual void defend() const {
        cout << "CLANG! " << getName() << " says: Take that in the name of my lord," << getLord() -> getName() << endl;
    }
private:
};



int main() {
    Lord sam("Sam");
    Archer samantha("Samantha", 200);
    sam.hires(samantha);
    Lord joe("Joe");
    PersonWithStrengthToFight randy("Randolf the Elder", 250);
    joe.battle(randy);
    joe.battle(sam);
    Lord janet("Janet");
    Swordsman hardy("TuckTuckTheHardy", 100);
    Swordsman stout("TuckTuckTheStout", 80);
    janet.hires(hardy);
    janet.hires(stout);
    PersonWithStrengthToFight barclay("Barclay the Bold", 300);
    janet.battle(barclay);
    janet.hires(samantha);
    Archer pethora("Pethora", 50);
    Archer thora("Thorapleth", 60);
    Wizard merlin("Merlin", 150);
    janet.hires(pethora);
    janet.hires(thora);
    sam.hires(merlin);
    janet.battle(barclay);
    sam.battle(barclay);
    joe.battle(barclay);
    
}

