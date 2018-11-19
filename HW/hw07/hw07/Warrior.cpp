//
//  Warrior.cpp
//  hw07
//
//  Created by Danny Tan on 3/31/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

#include "Warrior.h"
#include "Noble.h"
#include <iostream>

using namespace std;

namespace WarriorCraft{
    //constructor for warrior
    Warrior::Warrior(const std::string& name, int someStr): warriorName(name), str(someStr),
        noblePtr(nullptr){};
    //gets the warrior's name
    string Warrior::getName() const{
        return warriorName;
    }
    //gets the warrior's noble
    Noble* Warrior::getNoble(){
        return noblePtr;
    }
    //assign the warrior to a noble
    void Warrior::setNoble(Noble* someNoblePtr){
        noblePtr = someNoblePtr;
    }
    //warrior runs away from noble
    void Warrior::runaway(){
        if (noblePtr != nullptr){
            cout << getName() << " flees in terror, abandoning his lord, " <<  getNoble() -> getName()
                << endl;
            getNoble()->fire(*this);
            setNoble(nullptr);
            return;
        }
        cout << "Warrior is not hired" << endl;
    }
    //gets the str of the warrior
    int Warrior::getStr() const{
        return str;
    }
    //sets the str of teh warrior
    void Warrior::setStr(int newStr) {
        str = newStr;
    }
    
}
