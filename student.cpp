#include "student.h"
#include <iostream>

#if 0
Justin Iness
1/16/2022
C++ Programming
Learning about linked lists
#endif

using namespace std;

Student::Student() { // constructor
        cout << "Please enter the student's first name:  ";
	cin >> this->firstName;
	cout << "Please enter the student's last name:  ";
	cin >> this->lastName;
	cout << "Please enter the student's ID:  ";
	cin >> this->id;
	cout << "Please enter the student's GPA:  ";
	cin >> this->gpa;
}
Student::~Student() { // destructor
        cout << "Node destructor called" << endl;
}

//getters and setters
char* Student::getFirst() {
        return this->firstName;
}
char* Student::getLast() {
        return this->lastName;
}
int Student::getID() {
	return this->id;
}
float Student::getGPA() {
	return this->gpa;
}
