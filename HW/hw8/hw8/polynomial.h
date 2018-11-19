//
//  Polynomial.h
//  hw8
//
//  Created by Danny Tan on 4/27/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

#ifndef Polynomial_h
#define Polynomial_h

#include <iostream>
#include <string>
#include <vector>

struct Node {
    Node(int data = 0, Node* next = nullptr);
    int data;
    Node* next;
};

class Polynomial{
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& rhs);
public:
    Polynomial();
    Polynomial(std::vector<int> coefficients);
    Polynomial(const Polynomial& poly);
    ~Polynomial();
    Polynomial& operator=(const Polynomial& rhs);
    Polynomial& operator += (const Polynomial& rhs);
    bool operator==(const Polynomial& rhs) const;
    void listAddToEnd(int data);
    int evaluate(int x) const;
private:
    Node* coefficient;
    int degree;
};

void listAddHead(Node*& headPtr, int data);
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
bool operator != (const Polynomial& lhs, const Polynomial& rhs);

#endif /* Polynomial_h */
