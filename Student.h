#ifndef STUDENT
#define STUDENT

#include <stdlib.h>
#include <string>
class Student;
#include "Course.h"


using namespace std;
class Student
{
    

    private:

        string Bnumber;
        string firstName;
        string lastName;
        string* enrolledCoursesByCRN;
        int numEnrolledCourses;
        int maxCapacity;

    public:
        Student(string bnum, string first_name, string last_name);
        Student();
       
        void show(string BuNumber);
        void setBuNumber(string bnumber);
        void enroll(string crn);
        void resize(int newCapacity);
        bool hasEnrolled(string crn);
        string getName();
        string getBuNumber();
        Student& operator=(const Student& other);
        bool operator==(const Student& other) const;
        string* GetArrayOfCRNs();
        
       
       

         ~Student();  
};

#endif
