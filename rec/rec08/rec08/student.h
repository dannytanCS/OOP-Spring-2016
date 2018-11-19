//
//  student.h
//  rec08
//
//  Created by Danny Tan on 3/24/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

#ifndef student_h
#define student_h
#include <string>
#include <vector>

namespace BrooklynPoly {
    class Course;
    class Student{
    public:
        Student (const std::string& studentName);
        void addCourse(const std::string& courseName);
        void dropCourse(const std::string& courseName);
        std::string getName() const;
        void display() const;
    private:
        std::string name;
        std::vector <Course*> courses;
    };
}

#endif /* student_h */
