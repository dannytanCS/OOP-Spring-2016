//
//  main.cpp
//  rec09
//
//  Created by Danny Tan on 3/31/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

/*
 Recitation 09
 CS1124
 John Sterling
 
 Focus: Copy Control.  Uses dynamic array of pointers.
 */

#include <string>
#include <iostream>
using namespace std;

class Position {
public:
    Position(const string& aTitle, double aSalary)
    : title(aTitle), salary(aSalary) {}
    string getTitle() const {return title;}
    double getSalary() const {return salary;}
    void changeSalaryTo(double d) {salary = d;}
private:
    string title;
    double salary;
};

class Entry {
public:
    Entry(const string& aName, unsigned aRoom, unsigned aPhone, Position& aPosition)
    : name(aName), room(aRoom), phone(aPhone), pos(&aPosition) {}
    friend ostream& operator<<( ostream& os, const Entry& e ) {
        os << e.name << '\n'
        << e.room << '\n'
        << e.phone;
        return os;
    }
    string getName() const{
        return name;
    }
    unsigned getPhone() const{
        return phone;
    }
private:
    string name;
    unsigned room;
    unsigned phone;
    Position* pos;
}; // Entry

class Directory {
    friend ostream& operator<<(ostream& os, const Directory& someDirectory);
public:
    Directory()
    : capacity(2), size(0), entries(new Entry*[2] )
    {
        for (size_t i = 0; i < capacity; i++) {
            entries[i] = NULL;
        }
    }
    Directory(const Directory& someDirectory){
        cout << "Copy Constructor" << endl;
        entries = new Entry* ();
        for (size_t i = 0; i < size; i++){
            if (entries[i] != nullptr){
                entries[i] = new Entry(*someDirectory.entries[i]);
                *entries[i] = *someDirectory.entries[i];
            }
        }
        size = someDirectory.size;
        capacity = someDirectory.capacity;
    }
    Directory& operator=(const Directory& someDirectory){
        if (this != &someDirectory){
            delete entries;
            entries = new Entry* ();
            for (size_t i = 0; i < size; i++){
                if (entries[i] != nullptr){
                    entries[i] = new Entry(*someDirectory.entries[i]);
                    *entries[i] = *someDirectory.entries[i];
                }
            }
            size = someDirectory.size;
            capacity = someDirectory.capacity;
        }
        return *this;
    }
    void add(const string& name, unsigned room, unsigned ph, Position& pos) {
        if (capacity == 0){
            entries = new Entry*[1];
            capacity = 1;
        }
        if( size == capacity ){
            Entry** oldEntry = entries;
            entries = new Entry*[ capacity *= 2 ];
            for (size_t i = 0; i < size; ++i){
                entries[i]=oldEntry[i];
            }
            delete[] oldEntry;
            capacity *= 2;
        }
        entries[size++] = new Entry(name, room, ph, pos);
        size++;
    }
    unsigned operator[](const string& name){
        for (size_t i = 0; i < size; i++){
            if (entries[i] != nullptr){
                if (entries[i] -> getName() == name){
                    return entries[i] -> getPhone();
                }
            }
        }
        return 0;
    }
    ~Directory(){
        cout << "Destructor" << endl;
        for (size_t i = 0; i < size; i++){
            delete entries[i];
        }
        delete[] entries;}
    
private:
    Entry** entries;
    size_t size;
    size_t capacity;
};

ostream& operator<<(ostream& os, const Directory& someDirectory){
    for (size_t i = 0; i < someDirectory.size; i++){
        if (someDirectory.entries[i] != nullptr){
            cout << *someDirectory.entries[i] << endl;
        }
    }
    os << "Size: " << someDirectory.size << " Capacity: " << someDirectory.capacity << endl;
    return os;
}

int main() {
    
    // Model as if there are these four kinds
    // of position in the problem:
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);
    
    //
    Directory d;
    d.add("Marilyn", 123, 4567, boss);
    Directory d2 = d;	// What function is being used.
    d2.add("Gallagher", 111, 2222, techie);
    Directory d3;
    d3 = d2;
    cout << d2;
    cout << d3["Marilyn"] << endl;
}
