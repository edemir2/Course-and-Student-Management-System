
#include "StudentList.h"
#include <stdlib.h>

using namespace std;


StudentList::StudentList()
{
    capacity = 1;
    currentQuantity = 0;
    listOfStudents = new Student[capacity];
}

int StudentList::getCurrentQuantitiy()
{
    return currentQuantity;
}

void StudentList::resizeArray() 
{
    this->capacity = 2 * this -> capacity;
    Student* resizedArray = new Student[this->capacity];

    for (int i = 0; i < this->currentQuantity; i++)
    {
        resizedArray[i] = listOfStudents[i];
    }
    delete[] listOfStudents;
    listOfStudents = resizedArray;
}




Student* StudentList::getStudent(string BuNumber)
{
    for (int i = 0; i < currentQuantity; i++) {
        
        if (listOfStudents[i].getBuNumber() == BuNumber) {
            return &listOfStudents[i];
        }
    }
    // Return an empty student object if the BuNumber is not found
    return nullptr;
}


void StudentList::insertStudent(Student newStudent)
{
    if(currentQuantity ==  capacity)
    {
        resizeArray();
    }
    listOfStudents[currentQuantity] = newStudent;
    currentQuantity++;
}

bool StudentList::hasBuNumber(string bunumber)
{
     bool hasBU = false;

   // Check if any student in the roster has the same CRN
   for (int i = 0; i < currentQuantity; i++) {
      if (listOfStudents[i].getBuNumber() == bunumber) {
         hasBU = true;
         break;
      }
   }
   
   return hasBU;
}

void StudentList::removeStudent(Student studentToRemove)
{
    for (int i = 0; i < currentQuantity; i++)
    {
        if (listOfStudents[i] == studentToRemove)
        {
            for (int j = i; j < currentQuantity - 1; j++)
            {
                listOfStudents[j] = listOfStudents[j + 1];
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

StudentList::~StudentList()
{
    delete[] listOfStudents;
}
