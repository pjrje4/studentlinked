#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip> 
#include "student.h"
#include "node.h"


#if 0
Justin Iness
1/30/2021
Linked Student List Main
C++ Programming
#endif

using namespace std;

//functions
void addStudent(Node* checkn, Node* addn);
void printStudents(Node* n);
void deleteStudent(Node* n, int sid, Node** head);
float average(Node* n, float gpas, int total);

int main() {
	Node* head = NULL;
	while (true) { //loop
		char input[20];
		cout << "Enter a command (ADD, PRINT, DELETE, AVERAGE, QUIT): ";
		cin >> input;
		if (strcmp(input, "ADD") == 0) { //add students
			Student* student = new Student(); // student
			Node* node = new Node(student); // node linked to student
			node->setNext(NULL); // clear
			//if list len = 0
			if (head == NULL) {
				head = node;
			}
			//if less then head (put in first)
			else if (node->getStudent()->getID() < head->getStudent()->getID()) {
				node->setNext(head);
				head = node;
			}
			else {
				addStudent(head, node); // recursive through list
			}
		}
		else if (strcmp(input, "PRINT") == 0) { //print students
			printStudents(head);
		}
		else if (strcmp(input, "DELETE") == 0) { //delete students
			cout << "What is the students ID?" << endl;
			cin >> input;
			deleteStudent(head, stoi(input), &head);
		}
		else if (strcmp(input, "AVERAGE") == 0) { //average gpas
			cout << setprecision(3);
			cout << average(head, 0, 0) << endl;
		}
		else if (strcmp(input, "QUIT") == 0) { //quit program
			return 0;
        	}
	}
}


void addStudent(Node* checkn, Node* addn) {
	//if not end of list
	if (checkn->getNext() != NULL) {
		if (checkn->getNext()->getStudent()->getID() < addn->getStudent()->getID()) { // if greater then next
			addStudent(checkn->getNext(), addn);
			return;
		}	
	//if less then next
		else {
			addn->setNext(checkn->getNext()); // insert node here
		}
	}
	checkn->setNext(addn);
}
void printStudents(Node* n) {
	if (n == NULL) { // empty list
		return;
	}
	cout << setprecision(3); // 2 decimals
	cout << n->getStudent()->getFirst() << " " << n->getStudent()->getLast() << " " << n->getStudent()->getID() << " " << n->getStudent()->getGPA() << endl; // output student info
	if (n->getNext() != NULL) { // as long as not end of list recursive
		printStudents(n->getNext());
	}
}
	
void deleteStudent(Node* n, int sid, Node** head_ptr) {
	Node* temp = NULL;
	//list len 0
	if (n == NULL) {
		return;
	}
	//if head == delete id
	if (n->getStudent()->getID() == sid) {
		if (n->getNext() == NULL) { // 1 long list and head
			delete n;
			*head_ptr = NULL;
			return;

		}
		else { // first of list > len 1
		        temp = n;
			*head_ptr = n->getNext();
			cout << "delete head" << endl;
			delete temp;
			cout << "returning head" << endl;
			return;
		}
	}
	else { // middle, end or not in list
		if (n->getNext() == NULL) { // not in list
			cout << "not in list" << endl;
			return;
		}
		if (n->getNext()->getStudent()->getID() == sid) { // found delete id
			//end of list
			if (n->getNext()->getNext() == NULL) {
				temp = n->getNext();
				n->setNext(NULL);
				cout << "delete end" << endl;
				delete temp;
				return;
			}
			// middle of list
			else {
				temp = n->getNext();
				n->setNext(n->getNext()->getNext());
				cout << "delete middle" << endl;
				delete temp;
				return;
			}
		}
		else {
			// recurse
			cout << "recurse" << endl;
			deleteStudent(n->getNext(), sid, head_ptr);
			return;
		}
	}
}
		
float average(Node* n, float gpas, int total) {
	if (n == NULL) { // len 0
		return 0;
	}
	gpas = gpas + n->getStudent()->getGPA();
	total++;
	//add up gpas and total
	if (n->getNext() != NULL) { // recurse if not end
		average(n->getNext(), gpas, total);
	}
	else { // return average gpas / total
		return (gpas / total);
	}

}


