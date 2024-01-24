#include <iostream>
#include <string>
#include "CourseList.h"
#include "StudentList.h"

CourseList courselist;
StudentList studentlist;

using namespace std;

Student::Student(string bnum, string name, string surname)
{
   Bnumber = bnum;
   firstName = name;
   lastName = surname;
   numEnrolledCourses = 0;
   maxCapacity = 10;
   enrolledCoursesByCRN = new string[maxCapacity];
}

Student::Student()
{
   Bnumber="";
   firstName="";
   lastName="";
   numEnrolledCourses = 0;
   maxCapacity = 10;
   enrolledCoursesByCRN = new string[maxCapacity];
}

string* Student::GetArrayOfCRNs() {
    return enrolledCoursesByCRN;
}


string Student::getName()
{
   return firstName +" "+ lastName;
}

void Student::setBuNumber(string bnumber)
{
   Bnumber = bnumber;
}

string Student::getBuNumber()
{
   return Bnumber;
}



void Student::resize(int newCapacity) {
    string *temp = new string[newCapacity];
   
    for (int i = 0; i < numEnrolledCourses; i++) {
        temp[i] = enrolledCoursesByCRN[i];
    }
    maxCapacity = newCapacity;
    delete[] enrolledCoursesByCRN;
    
    enrolledCoursesByCRN = temp;
}

void Student::enroll(string crn) 
{
    
    // Resize the enrolledCourses array if needed
    if (numEnrolledCourses >= maxCapacity) {
        resize(maxCapacity * 2);
    }

    // Add the course CRN to the enrolledCoursesByCRN array
    enrolledCoursesByCRN[numEnrolledCourses] = crn;
    std::cout<<"oncesi "<<numEnrolledCourses<<std::endl;
    numEnrolledCourses++;
    std::cout<<"sonrasi "<<numEnrolledCourses<<std::endl;
}

bool Student::hasEnrolled(string crn) 
{
   
    for (int i = 0; i < numEnrolledCourses; i++) {
       
        if (enrolledCoursesByCRN[i] == crn) 
        {
            return true;
        }
         std::cout<< "list: "<<enrolledCoursesByCRN[i]<<" crn: " << crn << std::endl;
        
    }
    return false;
    
   
}

 bool Student::operator==(const Student& other) const 
{
     return (this->Bnumber == other.Bnumber);
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        Bnumber = other.Bnumber;
        firstName = other.firstName;
        lastName = other.lastName;
        numEnrolledCourses = other.numEnrolledCourses;
        maxCapacity = other.maxCapacity;

        // deep copy enrolledCoursesByCRN
        delete[] enrolledCoursesByCRN;
        enrolledCoursesByCRN = new string[maxCapacity];
        for (int i = 0; i < numEnrolledCourses; i++) {
            enrolledCoursesByCRN[i] = other.enrolledCoursesByCRN[i];
        }
    }
    return *this;
}


void Student::show(string bnum) {
    
    Student *student = studentlist.getStudent(bnum);

    cout << "Student: " << student->getBuNumber() << ": " << student->getName() << endl;

    for (int i = 0; i < numEnrolledCourses; i++) {
        Course *course = courselist.findCourse(enrolledCoursesByCRN[i]);
        cout << course->getCRN() << " " << course->getDepartment() << " " << course->getDepNumber() << " " << course->getCourseName() << endl;
    }
}

Student::~Student() {
   delete[] enrolledCoursesByCRN;
}


