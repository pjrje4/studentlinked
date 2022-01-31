#include <iostream>

#if 0
Justin Iness
1/16/2022
C++ Programming
Learning about linked lists
#endif

#ifndef STUDENTHEAD
#define STUDENTHEAD

using namespace std;

class Student {
        public:
                Student(); // constructor
		~Student(); //deconstructor
		char* getFirst(); // getters and setters
		char* getLast();
		int getID();
		float getGPA();
        protected: // student info
        	char firstName[20];
		char lastName[20];
		int id;
		float gpa;
};

#endif
