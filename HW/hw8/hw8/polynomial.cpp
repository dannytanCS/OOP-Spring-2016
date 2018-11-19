//
//  main.cpp
//  hw8
//
//  Created by Danny Tan on 4/27/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

#include "polynomial.h"

using namespace std;

//Node constructor
Node::Node(int data, Node* next) : data(data), next(next) {}

//add a Node to the head of list
void listAddHead(Node*& headPtr, int data) {
    headPtr = new Node(data, headPtr);
}

//default polynomial constructor
Polynomial::Polynomial(): degree(0), coefficient(nullptr) {}

//polynomial constructor which takes in a vector
Polynomial::Polynomial (vector<int> coefficients): degree(coefficients.size()-1), coefficient(nullptr)
{   //sets the coefficients as a linked list from lowest degree to highest
        size_t size = coefficients.size();
        for (size_t i = 0; i < size; ++i){
            listAddHead(coefficient, coefficients[i]);
        }
}

// polynomial copy constructor
Polynomial::Polynomial(const Polynomial& poly){
    //copy all the data from poly
    coefficient = nullptr;
    degree = poly.degree;
    Node* p = poly.coefficient;
    while (p){
        listAddToEnd(p -> data);
        p = p -> next;
    }
}
//polynomial destructor
Polynomial::~Polynomial(){
    //clears all the data in polynomial
    while (coefficient){
        Node* temp = coefficient;
        coefficient = coefficient -> next;
        delete temp;
    }
    coefficient = nullptr;
    degree = 0;
}
// assign operator
Polynomial& Polynomial::operator=(const Polynomial& rhs){
    //clears all the data
    while (coefficient){
        Node* temp = coefficient;
        coefficient = coefficient -> next;
        delete temp;
    }
    //copy all the data from rhs
    coefficient = nullptr;
    degree = rhs.degree;
    Node* p = rhs.coefficient;
    while (p){
        listAddToEnd(p -> data);
        p = p -> next;
    }
    return *this;
}
// adds data to the end of a list
void Polynomial::listAddToEnd(int data) {
    if (coefficient == nullptr) {
        coefficient = new Node(data);
    }
    else {
        Node* p = coefficient;
        while (p->next) {
            p = p->next;
        }
        p->next = new Node(data);
    }
    return;
}
// adds a polynomial to itself
Polynomial& Polynomial::operator += (const Polynomial& rhs){
    if(rhs.degree > degree){
        degree = rhs.degree;
    }
    Node* temp = coefficient;
    Node* temp2 = rhs.coefficient;
    while (temp2){
        if (temp){
            temp -> data += temp2 -> data;
            temp = temp -> next;
        }
        // if degree of two is bigger than one, then just add to end the data of two to one.
        else{
            listAddToEnd(temp2 -> data);
        }
        temp2 = temp2 -> next;
    }
    return *this;
}
//adds two polynomials
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs){
    Polynomial poly = lhs;
    poly += rhs;
    return poly;
}

//checks if two polynomials are equal
bool Polynomial::operator==(const Polynomial& rhs) const{
    Node* p = coefficient;
    Node* q = rhs.coefficient;
    //checks if their degrees are equal
    if (degree == rhs.degree){
        //checks if their data are equal until the end
        while (p != nullptr && p -> data == q -> data){
            p = p -> next;
            q = q -> next;
        }
    }
    return ( p == nullptr && q == nullptr);
}
//compares two polynomial
bool operator != (const Polynomial& lhs, const Polynomial& rhs){
    return !(lhs == rhs);
}
//evaluate the polynomial at x
int Polynomial::evaluate(int x) const{
    if (coefficient == nullptr){
        return 0;
    }
    int answer = 0;
    int degree = 0;
    Node* p = coefficient;
    //loops through the linked list
    while (p){
        int exp = 1;
        //evaluate the exponent part of the polynomial (x^4)
        for (int i = 0; i < degree; ++i){
            exp *= x;
        }
        //multiply the exponent part to the coeffient
        answer += p -> data * exp;
        p = p -> next;
        ++degree;
    }
    return answer;
}

//output operator
ostream& operator<<(ostream& os, const Polynomial& rhs){
    if(rhs.coefficient == nullptr){
        os<<0;
    }
    else{
        Node* p = rhs.coefficient;
        int temp = rhs.degree;
        while (temp != 0){
            p = rhs.coefficient;
            int counter = 0;
            //loops to the current position that was saved
            while(counter != temp){
                p = p -> next;
                ++ counter;
            }
            //if the coefficient is not 0
            if (p -> data != 0){
                //if degree is 1, print x without exponent
                if(temp == 1){
                    os << p -> data << "x" << " + " ;
                }
                else{
                    os << p -> data << "x^" << temp << " + " ;
                }
            }
            //decreasing the number of degree, looping backwards
            --temp;
        }
        //prints out the case where degree is 0
        os << rhs.coefficient->data;
    }
    return os;
}
