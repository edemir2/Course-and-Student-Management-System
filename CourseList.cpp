
#include <stdlib.h>
#include "CourseList.h"
#include "Course.h"
#include <regex>
#include <iostream>

CourseList::CourseList()
{
    capacity = 1;
    currentQuantity = 0;
    listOfCourses = new Course[capacity];
    //listOfBuNumbers = new string[1];
}



Course* CourseList::findCourse(string crn) 
{
    
    for (int i = 0; i < currentQuantity; i++) {
        if (listOfCourses[i].getCRN() == crn) {
            return &listOfCourses[i];
        }
    }

    // Return an empty course if the course is not found
    return nullptr;
}

void CourseList::setCapacity(int cap)
{
    capacity = cap;
}
void CourseList::setCurrentQuantity(int qua)
{
    currentQuantity = qua;
}
int CourseList::getCurrentQuantity()
{
    return currentQuantity;
}           
int CourseList::getCapacity()
{
    return capacity;
}

void CourseList::insertCourse(Course newCourse)
{

    if(currentQuantity ==  capacity)
    {
        
        resizeArray();
        
    }
   

    listOfCourses[currentQuantity] = newCourse;
    currentQuantity++;

    

}

void CourseList::resizeArray()
{
    

    this->capacity = 2 * this -> capacity;
    Course* resizedArray = new Course[this->capacity];

    for (int i = 0; i < this->currentQuantity; i++)
    {
        resizedArray[i] = listOfCourses[i];
    }
    delete[] listOfCourses;
    listOfCourses = resizedArray;
    //delete[] resizedArray;
}



bool CourseList::hasCRN(string crn) 
{
   bool hasCrn = false;

   // Check if any student in the roster has the same CRN
   for (int i = 0; i < currentQuantity; i++) {
      if (listOfCourses[i].getCRN() == crn) {
         hasCrn = true;
         break;
      }
   }
   
   return hasCrn;
}

void CourseList::removeCourse(string crn)
{
    for (int i = 0; i < currentQuantity; i++)
    {
        if (listOfCourses[i].getCRN() == crn)
        {
            for (int j = i; j < currentQuantity - 1; j++)
            {
                listOfCourses[j] = listOfCourses[j + 1];
            }
            currentQuantity--;
            
            // Check if array size needs to be reduced
            if (currentQuantity <= capacity / 4)
            {
                resizeArray();
            }
            
            return;
        }
    }
}

CourseList::~CourseList()
{
    delete[] listOfCourses;
}

