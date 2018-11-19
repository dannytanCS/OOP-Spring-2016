//
//  Noble.cpp
//  hw07
//
//  Created by Danny Tan on 3/31/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

#include "Noble.h"
#include "Warrior.h"
#include <iostream>

using namespace std;

namespace WarriorCraft {
    //noble constructor
    Noble::Noble (const std::string& name): nobleName(name), dead(false){};
    //returns the noble's army
    vector <Warrior*> Noble::getArmy()const{
        return army;
    }
    //operator overload for cout
    ostream& operator<<(ostream& os, const Noble& noble){
        os << noble.getName() << " has an army of " << (noble.getArmy)().size() << endl;
        for (Warrior* warrior: noble.getArmy()){
            os << warrior -> getName() << ": " << warrior -> getStr() << endl;
        }
        return os;
    }
    //hires a warrior
    void Noble::hire(Warrior& warrior){
        if (isHeDead() == false){
            for (size_t i = 0; i < army.size(); i++){
                if (army[i] == &warrior){
                    cout << warrior.getName() << " is already hired." << endl;
                    return;
                }
            }
            army.push_back(&warrior);
            warrior.setNoble(this);
            return;
        }
        cout << "Noble is dead. Cannot hire." << endl;
    }
    //fires a warrior
    void Noble::fire(Warrior& warrior){
        for (size_t i = 0; i < army.size(); i++){
            if (army[i] == &warrior){
                army[i] = army[army.size()];
                army.pop_back();
                warrior.setNoble(nullptr);
                return;
            }
        }
        cout << warrior.getName() << " is not hired" << endl;
    }
    //checks if noble is dead
    bool Noble::isHeDead() const {
        return dead;
    }
    //sets the death of the noble
    void Noble::setDeath(){
        dead = true;
    }
    //gets the name of the noble
    string Noble::getName() const{
        return nobleName;
    }
    //finds the total strength of the army
    float Noble::totalStr() const {
        float str = 0;
        for (Warrior* warrior: army){
            str += warrior -> getStr();
        }
        return str;
    }
    //changes the strength of the army
    void Noble::changeStr(float multiplier) {
        for (Warrior* warrior: army){
            warrior -> setStr((warrior -> getStr())* multiplier);
        }
    }
    //battle method with another noble
    void Noble::battle(Noble& someNoble){
        cout << getName() << " battles " << someNoble.getName() << endl;
        //checks if either noble is dead
        if (isHeDead() == false){
            if (someNoble.isHeDead() == false) {
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
}