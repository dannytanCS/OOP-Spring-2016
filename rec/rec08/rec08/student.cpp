//
//  student.cpp
//  rec08
//
//  Created by Danny Tan on 3/24/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

#include "student.h"
#include "course.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace BrooklynPoly {
    class Course;
    Student::Student(const string& studentName) : name(studentName) {}
    void Student::addCourse(const string& courseName){
        courses.push_back(new Course(courseName));
    }
    void Student::dropCourse(const string& courseName){
        for (size_t i = 0; i < courses.size(); i++){
            if (courses[i]-> getName() == courseName){
                delete courses[i];
                courses[i] = courses[courses.size()];
                courses.pop_back();
            }
        }
        cout << courseName << "doesn't exist" << endl;
        return;
    }
    string Student::getName() const {
        return name;
    }
    void Student::display() const {
        cout << getName() << "(";
        for (Course* course: courses){
            cout << course -> getName() << " ";
        }
        cout << ")" << endl;
    }
}