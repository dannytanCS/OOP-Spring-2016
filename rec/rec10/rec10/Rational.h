//
//  Rational.h
//  rec10
//
//  Created by Danny Tan on 4/7/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

#ifndef Rational_h
#define Rational_h
#include <iostream>

namespace CS1124{
    class Rational{
        friend std::istream& operator>>(std::istream& lhs, Rational& rhs);
        friend std::ostream& operator<<(std::ostream& lhs,const Rational& rhs);
    public:
        Rational (int x = 0, int y = 1);
        void operator=(const Rational& rhs);
        Rational& operator+=(const Rational& b);
        Rational& operator++();
        Rational operator++(int dummy);
        int getNum()const;
        int getDem()const;
        void setNum(int num);
        void setDem(int dem);
    private:
        int numerator;
        int denominator;
    };
    Rational operator+(const Rational& lhs, const Rational& rhs);
    bool operator!=(const Rational& lhs, const Rational& rhs);
    Rational operator--(Rational& rhs);
    Rational operator--(Rational& lhs, int dummy);
    bool operator==(const Rational& lhs, const Rational&rhs);
    int GCF(int x, int y);
}
#endif /* Rational_h */

