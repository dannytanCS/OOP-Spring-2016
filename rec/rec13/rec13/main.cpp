//
//  main.cpp
//  rec13
//
//  Created by Danny Tan on 4/28/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node{
    Node (int data=0, Node* link=nullptr): data(data), next(link){}
    int data;
    Node* next;
};

void displayBinary(int num){
    if (num < 2) cout << num;
    else{
    displayBinary(num/2);
    cout << num%2;
    }
}

void listDisplay(Node* headPtr) {
    Node* p = headPtr;
    while(p != nullptr) {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

Node* listFindEnd(Node* headPtr) {
    if (headPtr == nullptr) {
        return nullptr;
    }
    Node* p = headPtr;
    while (p->next != nullptr) {
        p = p->next;
    }
    return p;
}

void listAddToEnd(Node*& headPtr, int data) {
    if (headPtr == nullptr) {
        headPtr = new Node(data);
    }
    else {
        Node* endPtr = listFindEnd(headPtr);
        endPtr->next = new Node(data);
    }
}


Node* sumList (Node* list1, Node* list2){
    if (list1 == nullptr) return nullptr;
    Node* sum = new Node(list1->data + list2->data, sumList(list1->next, list2->next));
    return sum;
}

struct TNode {
    TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
    int data;
    TNode *left, *right;
};

int max(TNode* root) {
    int maxNum = root -> data;
    if (root -> left){
        if (maxNum < max(root -> left)){
            maxNum = max (root -> left);
        }
    }
    if (root -> right){
        if (maxNum < max (root -> right)){
            maxNum = root -> right -> data;
        }
    }
    return maxNum;
}

int cStringSum(const char* arr){
    if (arr[0] == '\0') return 0;
    int sum = arr[0];
    sum += cStringSum(arr+1);
    return sum;
}

int binSearch(char* arr, int target, int low, int high) {
    if (low > high) return -1;
    int mid = low + (high-low) / 2;
    if (target == arr[mid]) return mid;
    else if (target < arr[mid]) {
        return binSearch(arr, target, low, mid-1);
    }
    else {
        return binSearch(arr, target, mid+1, high);
    }
}

void f(int n) {
    if (n > 1) {
        cout << 'a';
        f(n/2);
        cout << 'b';
        f(n/2);
    }
    cout << 'c';
}

int main(){
//    displayBinary(24);
//    cout << endl;
//    Node* list1;
//    listAddToEnd(list1,5);
//    listAddToEnd(list1,10);
//    Node* list2;
//    listAddToEnd(list2,50);
//    listAddToEnd(list2,15);
//    Node* list3;
//    list3 = sumList(list1, list2);
//    listDisplay(list3);
//    
    TNode a(1), b(2), c(4), d(8, &a, &b), e(91, &c), f(32, &d, &e);
    cout << max(&f) << endl;
    
    char cString [] {"I love C++"};
    cout << cStringSum(cString)<< endl;
    int* p = new int[10];
    char arr[] {'a','b','c','d','e','f','g','h','i','j'};
    cout << binSearch(arr, 'f', 0, 9) << endl;
    //f(2);
}
