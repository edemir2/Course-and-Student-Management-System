#ifndef COURSE
#define COURSE

#include <stdlib.h>
#include <string>
class Course;
#include "Student.h"


using namespace std;
class Course
{
   

    private:
       
        string CRN;
        string Department;
        string number;
        string courseName;
        string* rosterStudentsBuNum;
        int numOfStudents;
        int maxCapacity;

     public:
        Course(string crn, string dep, string num  ,string name);
        Course();
        void show(string crn);
        void setCRN(string CRN);
        string getCRN();
        void resize(int newSize);
        string getCourseName();
        string getDepartment();
        string getDepNumber();
        bool inTheClass(string buNumber, string crn);
        void addStudent(string buNumber);
        void removeStudent(string buNumber);
        Course& operator=(const Course& other);
        bool operator==(const Course& other) const; 
       
     

        ~Course();
       
};

#endif
