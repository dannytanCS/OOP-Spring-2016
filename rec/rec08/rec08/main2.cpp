//
//  main2.cpp
//  rec08
//
//  Created by Danny Tan on 3/26/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//


#include "registrar.h"
#include "student.h"
#include "course.h"
#include <iostream>
#include <fstream>
using namespace BrooklynPoly;
using namespace std;

int main() {
    ifstream ifs ("transactions.txt");
    if (!ifs) {
        cout << "File is not found" << endl;
    }
    Registrar registrar;
    string command;
    while (ifs >> command){
        if (command == "PrintReport"){
            registrar.printReport();
        }
        if (command == "AddCourse"){
            string courseName;
            bool courseExist = false;
            if (ifs >> courseName){
                for (Course* course: registrar.getCourses()){
                    if (course -> getName() == courseName){
                        courseExist = true;
                        cout << courseName << " already exist" << endl;
                    }
                }
                if (courseExist == false){
                    registrar.addCourse(courseName);
                }
            }
        }
        if (command == "AddStudent"){
            string studentName;
            bool studentExist = false;
            if (ifs >> studentName){
                for (Student* student: registrar.getStudents()){
                    if (student -> getName() == studentName){
                        studentExist = true;
                        cout << studentName << " already exist" << endl;
                    }
                }
                if (studentExist == false){
                    registrar.addStudent(studentName);
                }
            }
        }
        if (command == "EnrollStudentInCourse"){
            string courseName;
            string studentName;
            bool courseExist = false;
            bool studentExist = false;
            if (ifs >> studentName >> courseName){
                for (Student* student: registrar.getStudents()){
                    if (student -> getName() == studentName ){
                        studentExist = true;
                    }
                }
                for (Course* course: registrar.getCourses()){
                    if (course -> getName() == courseName){
                        courseExist = true;
                        }
                }
                if (courseExist == true && studentExist == true){
                    registrar.enrollStudentInCourse(studentName, courseName);
                }
                if (courseExist == false){
                    cout << courseName << " doesn't exist" << endl;
                }
                if (studentExist == false){
                    cout <<  studentName << " doesn't exist" << endl;
                }
            }
        }
        if (command == "CancelCourse"){
            string courseName;
            bool courseExist = false;
            if (ifs >> courseName){
                for (Course* course: registrar.getCourses()){
                    if (course -> getName() == courseName){
                        registrar.cancelCourse(courseName);
                        courseExist = true;
                    }
                }
                if (courseExist == false){
                    cout << courseName <<" doesn't exist" << endl;
                }
            }
        }
        if (command == "Purge"){
            registrar.purge();
        }
    }
    ifs.close();
    return 0;
}