//
//  registrar.h
//  rec08
//
//  Created by Danny Tan on 3/24/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

#ifndef registrar_h
#define registrar_h
#include <vector>
#include <string>


namespace BrooklynPoly {
    class Course;
    class Student;
    class Registrar {
        friend std::ostream& operator<<(std::ostream& lhs, Registrar rhs);
    public:
        void addCourse (const std::string& courseName);
        void addStudent (const std::string& studentName);
        void enrollStudentInCourse (const std::string& studentName, const std::string& courseName);
        void cancelCourse(const std::string& courseName);
        void printReport()const;
        void purge();
        std::vector<Course*> getCourses();
        std::vector<Student*> getStudents();
    private:
        std::vector<Course*> courses;
        std::vector<Student*> students;
        std::string findCourse(const std::string& courseName)const;
        std::string findStudent(const std::string& studentName)const;
    };
}

#endif /* registrar_h */
