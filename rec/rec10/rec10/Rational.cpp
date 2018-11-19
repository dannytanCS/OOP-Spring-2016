//
//  rec10.cpp
//  rec10
//
//  Created by Danny Tan on 4/7/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

#include "Rational.h"

using namespace std;

namespace CS1124{
    Rational::Rational (int x, int y): numerator(x), denominator(y){}
    istream& operator>>(std::istream& lhs, Rational& rhs){
        int num, den;
        char slash;
        lhs >> num >> slash >> den;
        rhs.numerator = num;
        rhs.denominator = den;
        return lhs;
    }
    int GCF(int x, int y) {
        while (y != 0) {
            int temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }
    int Rational::getNum()const{
        return numerator;
    }
    int Rational::getDem()const{
        return denominator;
    }
    void Rational::setNum(int num){
        numerator = num;
    }
    void Rational::setDem(int dem){
        denominator = dem;
    }
    ostream& operator<<(ostream& lhs,const Rational& rhs){
        int gcf = GCF(rhs.getNum(),rhs.getDem());
        if (gcf < 0){
            gcf = -1*gcf;
        }
        if (rhs.getNum() < 0 && rhs.getDem() < 0){
            lhs << -1*rhs.getNum()/gcf << "/" << -1*rhs.getDem()/gcf << endl;
        }
        else if(rhs.getDem() < 0){
            lhs << -1*rhs.getNum()/gcf << "/" << -1*rhs.getDem()/gcf << endl;
        }
        else{
            lhs << rhs.getNum()/gcf << "/" << rhs.getDem()/gcf << endl;

        }
        return lhs;
    }
    void Rational::operator=(const Rational& rhs){
        numerator = rhs.numerator;
        denominator = rhs.denominator;
    }
    Rational& Rational::operator+=(const Rational& rhs){
        if (denominator == rhs.denominator){
            numerator += rhs.numerator;
        }
        else{
            numerator = numerator*(rhs.denominator) + (rhs.numerator)*denominator;
            denominator *= rhs.denominator;
        }
        return *this;
    }
    Rational operator+(const Rational& lhs, const Rational& rhs){
        Rational result;
        result += lhs;
        result += rhs;
        return result;
    }
    bool operator==(const Rational& lhs,const Rational& rhs){
        return (lhs.getNum() * rhs.getDem() == rhs.getNum() * lhs.getDem());
    }
    bool operator!=(const Rational& lhs, const Rational& rhs){
        return !(lhs == rhs);
    }
    Rational& Rational::operator++(){
        numerator += denominator;
        return *this;
    }
    Rational Rational::operator++(int dummy){
        Rational result(*this);
        result.numerator += result.denominator;
        return result;
    }
    Rational operator--(Rational& rhs){
        rhs.setNum(rhs.getNum()-rhs.getDem());
        return rhs;
    }
    Rational operator--(Rational& lhs, int dummy){
        Rational result(lhs);
        result.setNum(result.getNum()-result.getDem());
        return result;
    }
}
