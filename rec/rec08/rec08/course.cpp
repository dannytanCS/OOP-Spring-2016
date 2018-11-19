//
//  course.cpp
//  rec08
//
//  Created by Danny Tan on 3/24/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

#include "course.h"
#include "student.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace BrooklynPoly {
    class Registrar;
    Course::Course (const string& courseName): name(courseName) {}
    void Course::addStudent(const string& studentName){
        students.push_back(new Student (studentName));
    }
    void Course::dropStudent(const string& studentName){
        for (size_t i = 0 ; i < students.size() ; i ++ ) {
            delete students[i];
            students[i] = students[students.size()];
            students.pop_back();
            return;
        }
        cout << studentName << "doesn't exists" << endl;
    }
    string Course::getName() const {
        return name;
    }
    void Course::display() const {
        cout << getName() << "(";
        for (Student* student: students){
            cout << student -> getName() << " ";
        }
        cout << ")" << endl;
    }
}