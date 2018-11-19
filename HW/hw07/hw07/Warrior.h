//
//  Warrior.h
//  hw07
//
//  Created by Danny Tan on 3/31/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

#ifndef Warrior_h
#define Warrior_h
#include <string>

//Warrior header
namespace WarriorCraft {
    class Noble;
    class Warrior{
    public:
        Warrior(const std::string& name, int someStr);
        void runaway();
        Noble* getNoble();
        void setNoble(Noble* someNoblePtr);
        std::string getName() const;
        int getStr() const;
        void setStr(int str);
    private:
        std::string warriorName;
        int str;
        Noble* noblePtr;
    };
}


#endif /* Warrior_h */
