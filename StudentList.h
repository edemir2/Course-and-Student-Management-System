#ifndef STUDENT_LIST
#define STUDENT_LIST

#include "Student.h"
#include <stdlib.h>
class StudentList
{
    private:
        int capacity;
        int currentQuantity;
        Student* listOfStudents;

    public:
        //Constructor
        StudentList();

        //Array Methods
        void insertStudent(Student newStudent);
        void resizeArray();
        void removeStudent(Student studentToRemove);
        bool hasBuNumber(string bunumber);
        Student* getStudent(string bnumber);
        int getCurrentQuantitiy();

        ~StudentList();

};

#endif