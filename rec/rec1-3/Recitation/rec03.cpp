//
//  rec03.cpp
//  Recitation
//
//  Created by Danny Tan on 2/11/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class CheeseSandwich {
public:
    void setCheese(int newCheese){
        cheese = newCheese;
    }
    void setMayo (double newMayo){
        mayonnaise = newMayo;
    }
    void setTomato (int newTomato){
        tomato = newTomato;
    }
    void setMustard (int newMustard){
        mustard = newMustard;
    }
    int displayBread() const{
        return bread;
    }
    int displayCheese() const{
        return cheese;
    }
    double displayMayo() const{
        return mayonnaise;
    }
    int displayTomato() const{
        return tomato;
    }
    double displayMustard() const{
        return mustard;
    }
    void display() const{
        cout << "Bread: " << bread << ", Cheese: " << cheese << ", Mayonnaise: " << mayonnaise << ", Tomato:" << tomato << ", Mustard: " << mustard << endl;
    }
    CheeseSandwich (int someCheese = 1, double someMayo = 1, int someTomato = 2, double someMustard = 0.05, const int bread = 2): bread(2), cheese(someCheese), mayonnaise(someMayo), tomato(someTomato),
    mustard(someMustard){}
private:
    const int bread;
    int cheese;
    double mayonnaise;
    int tomato;
    double mustard;
};

class SandwichTruck {
public:
    void insertSandwich (CheeseSandwich aCheeseSandwhich){
        vectorOfSandwich.push_back(aCheeseSandwhich);
    }
    void checkBeforeLeaving (){
        for (size_t index = 0; index < vectorOfSandwich.size(); index ++){
            vectorOfSandwich[index].display();
        }
    }
private:
    vector<CheeseSandwich> vectorOfSandwich;
};


int main(){
    CheeseSandwich CheeseSandwich1;
    CheeseSandwich CheeseSandwich2;
    CheeseSandwich2.setMustard(0);
    CheeseSandwich CheeseSandwich3;
    CheeseSandwich3.setCheese(2);
    CheeseSandwich CheeseSandwich4;
    SandwichTruck aSandwichTruck;
    aSandwichTruck.insertSandwich(CheeseSandwich1);
    aSandwichTruck.insertSandwich(CheeseSandwich2);
    aSandwichTruck.insertSandwich(CheeseSandwich3);
    aSandwichTruck.insertSandwich(CheeseSandwich4);
    aSandwichTruck.checkBeforeLeaving();
    cout << CheeseSandwich2.displayMustard() << endl;
    return 0;
}