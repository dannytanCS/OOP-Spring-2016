//
//  registrar.cpp
//  rec08
//
//  Created by Danny Tan on 3/24/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//


#include "registrar.h"
#include "course.h"
#include "student.h"
#include <string>
#include <iostream>

using namespace std;

namespace BrooklynPoly {
    void Registrar::addCourse(const string& courseName) {
        courses.push_back(new Course(courseName));
    }
    void Registrar::addStudent(const string& studentName){
        students.push_back(new Student(studentName));
    }
    void Registrar::cancelCourse(const string& courseName){
        for (size_t i = 0; i < courses.size(); i++) {
            if (courses[i]-> getName() == courseName){
                delete courses[i];
                courses[i] = courses[courses.size()];
                courses.pop_back();
                return;
            }
        }
        cout << courseName << "doesn't exist" << endl;
    }
    void Registrar::enrollStudentInCourse (const string& studentName, const string& courseName){
        for (Course* course: courses){
            if (course -> getName() == courseName){
                for (Student* student: students){
                    if (student -> getName() == studentName) {
                        course -> addStudent(studentName);
                        student -> addCourse(courseName);
                    }
                }
            }
        }
    }
    void Registrar::printReport()const{
        cout << "Course Name:" << endl;
        for (Course* course: courses){
            course -> display();
        }
        cout << "Student Name:" << endl;
        for (Student* student: students){
            student -> display();
        }
    }
    void Registrar::purge(){
        for (Student* student: students){
            delete student;
        }
        students.clear();
        for (Course* course: courses){
            delete course;
        }
        courses.clear();
    }
    ostream& operator<<(ostream& os, Registrar rhs){
        os << "Courses:" << endl;
        for (Course* course: rhs.courses){
            course -> display();
        }
        os << "Students:" << endl;
        for (Student* student: rhs.students){
            student -> display();
        }
        return os;
    }
    vector<Course*> Registrar::getCourses(){
        return courses;
    }
    vector<Student*> Registrar::getStudents(){
        return students;
    }
}