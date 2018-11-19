//
//  main.cpp
//  rec12
//
//  Created by Danny Tan on 4/21/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node {
    Node(int someData =0 , Node* link = nullptr) : data (someData), next(link) {}
    int data;
    Node* next;
};

class Sequence{
public:
    Sequence(): head(nullptr), current(nullptr){}
    Sequence(const Sequence& rhs){
        Node* temp = rhs.head;
        while (temp != nullptr){
            add(temp -> data);
            temp = temp -> next;
        }
    }
    ~Sequence(){
        clear();
    }
    Sequence& operator=(const Sequence& rhs){
        if (this != &rhs){
            clear();
            Node* temp = rhs.head;
            while (temp != nullptr){
                add(temp -> data);
                temp = temp -> next;
            }
        }
        return *this;
    }
    bool valid(){
        return current != nullptr;
    }
    void reset(){
        current = head;
    }
    void add(int someData){
        Node* New = new Node(someData);
        if (valid()){
            Node* temp = current -> next;
            current -> next = New;
            current -> next -> next = temp;
            current = current -> next;
            return;
        }
        head = New;
        current = head;
        return;
    }
    void remove(){
        Node* temp = head;
        while (temp -> next != current) {
            temp = temp -> next;
        }
        temp -> next = current -> next;
        delete current;
        current = temp -> next;
        return;
    }
    int data(){
        if (valid()){
            return current -> data;
        }
        return -1;
    }
    void next(){
        if (valid()){
            if (current -> next != nullptr){
                current = current -> next;
                return;
            }
            current = nullptr;
        }
        return;
    }
    void clear(){
        reset();
        while (current != nullptr){
            Node* temp = current;
            delete current;
            current = temp -> next;
        }
        head = nullptr;
    }
    void display(char separator = ' ', ostream& os = cout){
        Node* p = head;
        while (p != nullptr){
            os << p->data << separator;
            p = p -> next;
        }
        os << endl;
        return;
    }
    
private:
    Node* head;
    Node* current;
};

int main(){
    Sequence s;
    for (int i = 0; i < 6; ++i) s.add(i);
    s.display();
    cout << "Copy Constructor ===== \n";
    Sequence s2(s);
    s2.display();
    cout << "Assignment ======= \n";
    Sequence s3;
    s3 = s2;
    s3.display();
    s.reset();
    cout << "===========\n";
    for (int i = 0; i < 3; ++i) s.next();
    s.add(42);
    s.display();
    cout << "==========\n";
    s.reset();
    for (int i = 0; i < 2; ++i) s.next();
    s.remove();
    s.display();
    cout << "==========\n";
    s.clear();
    s.display();
    cout << "==========\n";
}
