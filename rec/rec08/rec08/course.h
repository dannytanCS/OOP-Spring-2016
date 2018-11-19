//
//  course.h
//  rec08
//
//  Created by Danny Tan on 3/24/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

#ifndef course_h
#define course_h

#include <string>
#include <vector>


namespace BrooklynPoly {
    class Student;
    class Course {
    public:
        Course(const std::string& courseName);
        void addStudent(const std::string& studentName);
        void dropStudent(const std::string& studentName);
        std::string getName() const;
        void display() const;
    private:
        std::vector <Student*> students;
        std::string name;
    };
}
#endif /* course_h */
