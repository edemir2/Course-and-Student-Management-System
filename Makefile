# Specifiy the target
all: Scheduler_cp2

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Scheduler_cp2: Student.o Course.o StudentList.o CourseList.o Scheduler_cp2.o
	g++ Student.o Course.o StudentList.o CourseList.o Scheduler_cp2.o -o Scheduler_cp2

# Specify how the object files should be created from source files
Student.o: Student.cpp Course.h
	g++ -c Student.cpp

Course.o: Course.cpp Course.h
	g++ -c Course.cpp

StudentList.o: StudentList.cpp CourseList.h
	g++ -c StudentList.cpp

CourseList.o: CourseList.cpp CourseList.h
	g++ -c CourseList.cpp
	
Scheduler_cp2.o: Scheduler_cp2.cpp StudentList.h CourseList.h
	g++ -c Scheduler_cp2.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Scheduler_cp2
 