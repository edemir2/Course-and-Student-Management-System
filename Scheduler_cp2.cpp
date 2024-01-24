#include <string>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <regex>
//#include "Student.h"
//#include "Course.h"
#include "StudentList.h"
#include "CourseList.h"

using namespace std;

bool BUn_check(const string& arg);
bool num_check(const string& arg); 
bool CRN_check(const string& arg);
bool dep_check(const string& arg);
bool name_check(const string& arg);
bool surname_check(const string& arg);
bool id_check(const string& arg);

int main() 
{
    StudentList studentlist;
    CourseList courselist;
    Student student;
    Course course;
    

	while (true) 
    {
		string inputString;
        getline(cin >> ws, inputString);

        //Define the dynamic array variable of strings
        vector<string> outputArray;

        //Construct a stream from the string
        stringstream streamData(inputString);
        string s;
       

        while (streamData >> s) 
        {
            
            // Remove leading and trailing whitespaces from s
            s.erase(0, s.find_first_not_of(" "));
            s.erase(s.find_last_not_of(" ") + 1);

            // Replace multiple whitespaces with a single space
            if (!outputArray.empty() && isspace(outputArray.back().back()) && isspace(s.front()))
            {
                outputArray.back() += " " + s.substr(s.find_first_not_of(" "));
            }
            else
            {
                outputArray.push_back(s);
            }
        }
    	
		if(outputArray[0] == "build") //build <crn> <department> <number> <name>
        {
            if(outputArray.size() < 5)
            {
                cout << "Input Error: too few arguments" << endl; continue;
            }
           

            else if(!CRN_check(outputArray[1]))
            {
                cout << "Input Error: illegal CRN" << endl; continue;
            }
            else if(!dep_check(outputArray[2]))
            {
                cout << "Input Error: illegal department" << endl; continue;
            }
            else if(!num_check(outputArray[3]))
            {
                cout << "Input Error: illegal course number" << endl; continue;
            }
            else if(!name_check(outputArray[4]))
            {
                cout << "Input Error: illegal Course Name" << endl; continue;
            }

             else if(courselist.hasCRN(outputArray[1]))
            {
                cout << "cannot build course CS240 (CRN: "<< outputArray[1] << "): CRN exists" << endl; continue;
            }
            else
            {
                Course* newCourse = new Course(outputArray[1],outputArray[2],outputArray[3],outputArray[4]);
                courselist.insertCourse(*newCourse);
                cout << "Success: built course " << outputArray[2]<< outputArray[3]<<" (CRN: "<< outputArray[1]<<"): "<< outputArray[4] << endl;
            }
		} 
        else if(outputArray[0] == "cancel") //cancel <crn>
        {
            if(outputArray.size()<2)
            {
                cout << "Input Error: too few arguments" << endl; continue;
            }

            else if(outputArray.size()>2)
            {
                cout << "Warning: ignoring extra argument(s)" << endl; continue;
            }

            else if(!CRN_check(outputArray[1]))
            {
                cout << "Input Error: illegal CRN" << endl; continue;
            }
            else if(!courselist.hasCRN(outputArray[1]))
            {
                cout << "Fail: cannot cancel course, CRN does not exist" << endl; continue;
            }

            else
            {
                courselist.removeCourse(outputArray[1]);
                cout << "Success: cancelled course " << outputArray[1] << endl;
            }

		}
        else if(outputArray[0] == "enroll") //enroll <bnumber> <userid> <first> <last>
        {


            if(outputArray.size()<5)
            {
                cout << "Input Error: too few arguments" << endl; continue;
            }

            else if(!BUn_check(outputArray[1]))
            {
                cout << "Input Error: illegal BU number" << endl; continue;
            }

            else if(!id_check(outputArray[2]))
            {
                cout << "Input Error: illegal User ID" << endl; continue;
            }

            else if(studentlist.hasBuNumber(outputArray[1]))
            {
                cout << "Fail: cannot enroll student, B Number exists"<<endl; continue;
            }

            else
            {
                Student* newStudent = new Student(outputArray[1], outputArray[3], outputArray[4]);
                //course.addStudent(outputArray[1]);
                studentlist.insertStudent(*newStudent);
                cout << "Success: enrolled student " << outputArray[1] <<"("<<outputArray[2]<<")"<< outputArray[3]<<","<< outputArray[4]<< endl; 
            }
            
			
		}

        else if(outputArray[0] == "add") //add <bnumber> <crn>
        {
            if(outputArray.size()<3)
            {
                cout << "Input Error: too few arguments" << endl; continue;
            }
            else if(!BUn_check(outputArray[1]))
            {
                cout << "Input Error: illegal BU number" << endl; continue;
            }

            else if(!CRN_check(outputArray[2]))
            {
                cout << "Input Error: illegal CRN" << endl; continue;
            }

            else if(course.inTheClass(outputArray[1],outputArray[2]))
            {
                cout<< "Fail: cannot add, student "<< outputArray[1] <<"already enrolled in course "<< outputArray[2] << endl; continue;
            }
            else
            {
                course.addStudent(outputArray[1]);
                student.enroll(outputArray[2]);
                cout << "Success: added student " << outputArray[1]<<" into course " << outputArray[2] << endl;
            }


        }
        else if(outputArray[0] == "drop") //drop <bnumber> <crn>
        {
             if(outputArray.size()<3)
            {
                cout << "Input Error: too few arguments" << endl; continue;
            }
            else if(!BUn_check(outputArray[1]))
            {
                cout << "Input Error: illegal BU number" << endl; continue;
            }

            else if(!CRN_check(outputArray[2]))
            {
                cout << "Input Error: illegal CRN" << endl; continue;
            }

             else if(!student.hasEnrolled(outputArray[2]))
            {
                cout<< "Fail: cannot drop, student "<< outputArray[1] <<" not enrolled in course "<< outputArray[2] << endl; continue;
            }

            else
            {
                course.removeStudent(outputArray[1]);
                cout << "Success: removed student "<< outputArray[1] <<" from course " << outputArray[2] <<endl;
            }
        }

        else if(outputArray[0] == "roster") //roster <crn>
        {
            if(outputArray.size()<2)
            {
                cout << "Input Error: too few arguments" << endl; continue;
            }
            else if(!CRN_check(outputArray[1]))
            {
                cout << "Input Error: illegal CRN" << endl; continue;
            }

            else
            {
                course.show(outputArray[1]);
            }
            
        }
        else if(outputArray[0] == "schedule") //schedule <bnumber>
        {
            if(!BUn_check(outputArray[1]))
            {
                cout << "Input Error: illegal BU number" << endl;
            }
            else
            {
                student.show(outputArray[1]);
            }
        }
        else if(outputArray[0] == "quit") 
        {
            break;
        }
        else
        {
            cout << "You must enter 'quit' to exit." << endl;
        }
	}
	
	return 0;
}

bool BUn_check(const string& arg)
{

    regex pattern("B\\d{8}");

    return regex_match(arg,pattern);
}

bool num_check(const string& arg) 
{
    //regex pattern("[100-700]\\d{3}");

    //return regex_match(arg, pattern);
    regex pattern("^(1[0-9][0-9]|2[0-9][0-9]|3[0-9][0-9]|4[0-9][0-9]|5[0-9][0-9]|6[0-9][0-9]|7[0-9][0-9])$");
    return regex_match(arg, pattern);
}

bool CRN_check(const string& arg)
{
    regex pattern("\\d{6}");

    return regex_match(arg, pattern);
    
}

bool dep_check(const string& arg) //must be a 2-4 character code, all caps
{
    regex pattern("[A-Z]{2,4}");

    return regex_match(arg, pattern);
}

bool name_check(const string& arg)
{
    regex pattern("[a-zA-Z]+(\\s+[a-zA-Z]+)*");

    return regex_match(arg, pattern);
}

bool surname_check(const string& arg)
{
    regex pattern("[a-zA-Z]+(\\s+[a-zA-Z]+)*");

    return regex_match(arg, pattern);
}

bool id_check(const string& arg)
{
    regex pattern("[a-zA-Z][a-zA-Z0-9]*");

    return regex_match(arg, pattern);
}
