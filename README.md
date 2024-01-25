# Course Management System (Mar 9, 2023)

## Introduction
The Course Management System is a command-line application designed for managing courses and student enrollments. It streamlines various administrative tasks such as course creation, cancellation, student enrollment, and more.

## Features
- **Build Courses:** Create new courses with unique identifiers.
- **Cancel Courses:** Remove existing courses.
- **Enroll Students:** Register students in the system.
- **Add Students to Courses:** Assign students to specific courses.
- **Drop Students from Courses:** Remove students from courses.
- **View Course Rosters:** Check the list of students enrolled in a course.
- **View Student Schedules:** See the courses a student is enrolled in.
- **Quit Program:** Exit the application.

## Usage
To perform operations, use the following commands:
- `build`: Create a new course with a specified CRN, department, course number, and name.
- `cancel`: Cancel a course using its CRN.
- `enroll`: Enroll a student using their B-number, user ID, first name, and last name.
- `add`: Add a student to a course using the student's B-number and course's CRN.
- `drop`: Drop a student from a course using the student's B-number and course's CRN.
- `roster`: Display the roster of a course using its CRN.
- `schedule`: Show a student's schedule using their B-number.
- `quit`: Exit the program.

## Code Structure
- `main.cpp`: Contains the main function and the command-line interface.
- `Student.cpp` and `Student.h`: Define the Student class with attributes and functionalities.
- `Course.cpp` and `Course.h`: Define the Course class with attributes and functionalities.
- `CourseList.cpp`: Manages a collection of courses.
- `StudentList.cpp`: Manages a collection of students.
- `Makefile`: Simplifies the compilation process.

## Getting Started
### Prerequisites
- Ensure a C++ compiler is installed on your system.

### Installation
1. Download the source code files, including the `Makefile`, to your local machine.
2. Use the `Makefile` to compile the code. Run the following command:
   ```bash
   make
3. Run the executable with:
    ```bash
   ./main

