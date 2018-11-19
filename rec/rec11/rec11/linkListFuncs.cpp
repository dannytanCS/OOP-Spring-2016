//
//  main.cpp
//  rec11
//
//  Created by Danny Tan on 4/14/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//


#include <string>
#include <iostream>

using namespace std;

struct Node {
    Node(int data = 0, Node* link = nullptr) : data(data), link(link) {}
    int data;
    Node* link;
};

void listInsertHead(int entry, Node*& headPtr) {
    headPtr = new Node(entry, headPtr);
}

Node* listEnd(Node* headPtr){
    if (headPtr != nullptr){
        while (headPtr -> link != nullptr){
            headPtr = headPtr -> link;
        }
    }
    return headPtr;
}

void listSplice(Node* prior, Node* headPtr2){
    if (headPtr2 != nullptr){
        Node* temp = prior -> link;
        prior -> link = headPtr2;
        listEnd(headPtr2) -> link = temp;
    }
}

void listDisplay(Node* headPtr){
    while (headPtr != nullptr){
        cout << headPtr -> data << " ";
        headPtr = headPtr -> link;
    }
    cout << endl;
}


Node* isSublist (Node* list1, Node* list2){
    Node* temp = nullptr;
    Node* temp2 = list2;
    while(list1) {
        if( list1->data == list2->data ){
            if(!list2->link){
                if(!temp){
                    temp = list1;
                }
                return temp;
            }
            else if(!temp){
                temp = list1;
                list1 = list1->link;
                list2 = list2->link;
            }
            else {
                list1 = list1->link;
                list2 = list2->link;
            }
        }
        else if(temp && list1->data != list2->data ) {
            list1 = temp->link;
            list2 = temp2;
            temp = nullptr;
        }
        else {
            list1 = list1->link;
        }
    }
    cout << "Failed to match";
    return nullptr;
}
int main(){
    Node* L1 = nullptr;
    listInsertHead(1, L1);
    listInsertHead(9, L1);
    listInsertHead(7, L1);
    Node* splicePtr = L1;
    listInsertHead(5, L1);
    Node* L2 = nullptr;
    listInsertHead(2, L2);
    listInsertHead(3, L2);
    listInsertHead(6, L2);
    listDisplay(L1);
    listDisplay(L2);
    listSplice(splicePtr, L2);
    listDisplay(L1);
    listDisplay(L2);
    Node* Target = nullptr;
    listInsertHead(6, Target);
    listInsertHead(5, Target);
    listInsertHead(4, Target);
    listInsertHead(2, Target);
    listInsertHead(3, Target);
    listInsertHead(2, Target);
    listInsertHead(3, Target);
    listInsertHead(2, Target);
    listInsertHead(1, Target);
    Node* AttemptMatch = nullptr;
    listInsertHead(4, AttemptMatch);
    listInsertHead(2, AttemptMatch);
    listInsertHead(3, AttemptMatch);
    listInsertHead(2, AttemptMatch);
    listDisplay(isSublist(Target, AttemptMatch));
    return 0;
}