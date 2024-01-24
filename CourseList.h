#ifndef COURSE_LIST
#define COURSE_LIST

#include <stdlib.h>
#include "Course.h"
#include <string>
class CourseList
{
    private:
        int capacity;
        int currentQuantity;
        Course* listOfCourses;
        //string* listOfBuNumbers;

    public:
        //Constructor
        CourseList();

        //Array Methods
        void insertCourse(Course newCourse);
        void resizeArray();
        void removeCourse(string crn);
        void setCapacity(int cap);
        void setCurrentQuantity(int qua);   
        int getCurrentQuantity();           
        int getCapacity();
        bool hasCRN(string crn);
        Course* findCourse(string crn);
        
       

        //Destructor
        ~CourseList();
       
};

#endif
