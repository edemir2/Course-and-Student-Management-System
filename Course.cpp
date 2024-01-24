
#include <iostream>
#include <string>
#include "Course.h"
#include "StudentList.h"
#include "CourseList.h"
#include "Student.h"

using namespace std;

StudentList studentlist1;
CourseList courselist1;

Course::Course(string crn, string dep, string num, string name) {
    CRN = crn;
    Department = dep;
    number = num;
    courseName = name;
    maxCapacity = 10; // initial size of the array
    numOfStudents = 0;
    rosterStudentsBuNum = new string[maxCapacity];
}

Course::Course() {
    CRN = "";
    Department = "";
    number = "";
    courseName = "";
    maxCapacity = 10; // initial size of the array
    numOfStudents = 0;
    rosterStudentsBuNum = new string[maxCapacity];
}




void Course::resize(int newSize) 
{
    // Create a new array with the new size
    string* newRosterStudentsBuNum = new string[newSize];
    
    // Copy the old array to the new array
    for (int i = 0; i < numOfStudents; i++) {
        newRosterStudentsBuNum[i] = rosterStudentsBuNum[i];
    }
    
    // Delete the old array
    delete[] rosterStudentsBuNum;
    
    // Set the new array as the rosterStudentsBuNum array
    rosterStudentsBuNum = newRosterStudentsBuNum;
    
    // Update the maxCapacity variable
    maxCapacity = newSize;

    delete[] newRosterStudentsBuNum;
}
//rosterStudentsBuNum
void Course::addStudent(string buNumber) 
{
    // Check if there is enough space in the rosterStudentsBuNum array
    if (numOfStudents == maxCapacity) {
        // If not, resize the array
        resize(maxCapacity * 2);
    }
    // Add the new student BuNumber to the array
    rosterStudentsBuNum[numOfStudents] = buNumber;
    numOfStudents++;
}

bool Course::inTheClass(string buNumber, string crn)
{
    Student *TheStudent = studentlist1.getStudent(buNumber);
    //std::cout<<"studentName: "<<TheStudent.getName()<<std::endl;

    // Loop through the rosterStudentBuNum array to find the student with the given BuNumber
    for (int i = 0; i < numOfStudents; i++) {

      
        if (TheStudent->GetArrayOfCRNs()[i] == crn) {

            // If the student is found, return true
            return true;
        }
    }
    // If the student is not found, return false
    return false;
}

void Course::removeStudent(string buNumber)
{
    // Find the index of the student with the given buNumber
    int index = -1;
    for (int i = 0; i < numOfStudents; i++) {
        if (rosterStudentsBuNum[i] == buNumber) {
            index = i;
            break;
        }
    }
    
    // If the student was found, remove them from the rosterStudentBuNum array
    if (index != -1) {
        for (int i = index; i < numOfStudents - 1; i++) {
            rosterStudentsBuNum[i] = rosterStudentsBuNum[i + 1];
        }
        numOfStudents--;
    }
}

string Course::getCourseName() {
    return courseName;
}

string Course::getDepartment() {
    return Department;
}

string Course::getDepNumber() {
    return number;
}

void Course::setCRN(string crn) {
    CRN = crn;
}

string Course::getCRN() {
    return CRN;
}

bool Course :: operator==(const Course& other) const 
{
    return (this->CRN == other.CRN);
}
        

Course& Course::operator=(const Course& other) 
{
    if (this != &other) 
    {
    	  	
        CRN = other.CRN;
        Department = other.Department;
        number = other.number;
        courseName = other.courseName;
        numOfStudents = other.numOfStudents;
        maxCapacity = other.maxCapacity;

        // deep copy rosterStudentsBuNum
        delete[] rosterStudentsBuNum;
        rosterStudentsBuNum = new string[maxCapacity];
        for (int i = 0; i < numOfStudents; i++) 
        {
           	rosterStudentsBuNum[i] = other.rosterStudentsBuNum[i];
        }
    }
    			
    	return *this;
}

void Course::show(string crn) {

        Course *course = courselist1.findCourse(crn);
        cout << "CRN: " << course->getCRN() << endl;

        cout << "Students: " << numOfStudents << endl;
        for (int i = 0; i < numOfStudents; i++) {
            Student *student = studentlist1.getStudent(rosterStudentsBuNum[i]);
            cout << student->getBuNumber() << " " << student->getName() << endl;
        }
    
}

Course::~Course() 
{
    delete[] rosterStudentsBuNum;
}

