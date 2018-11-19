//
//  Noble.h
//  hw07
//
//  Created by Danny Tan on 3/31/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

#ifndef Noble_h
#define Noble_h

#include <string>
#include <vector>

//Noble header
namespace WarriorCraft {
    class Warrior;
    class Noble{
        friend std::ostream& operator<<(std::ostream& lhs, const Noble& rhs);
    public:
        Noble (const std::string& name);
        std::vector<Warrior*> getArmy()const;
        void hire(Warrior& warrior);
        void fire(Warrior& warrior);
        std::string getName() const;
        void battle(Noble& noble);
        bool isHeDead() const;
        void setDeath();
        float totalStr() const;
        void changeStr(float multiplier);
    private:
        std::string nobleName;
        std::vector <Warrior*> army;
        bool dead;
    };
}

#endif /* Noble_h */
