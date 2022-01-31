#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip> 
#include "student.h"
#include "node.h"


/*
 *Justin Iness
 *11/17/2021
 *Student List
 * C++ Programming
 */

using namespace std;

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
			Student* student = new Student(); // student 1 node
			Node* node = new Node(student);
			node->setNext(NULL);
			//if list len = 0
			if (head == NULL) {
				head = node;
			}
			//if less then head
			else if (node->getStudent()->getID() < head->getStudent()->getID()) {
				node->setNext(head);
				head = node;
			}
			else {
				addStudent(head, node);
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
		else if (strcmp(input, "AVERAGE") == 0) { //delete students
			cout << setprecision(3);
			cout << average(head, 0, 0) << endl;
		}
		else if (strcmp(input, "QUIT") == 0) { //quit program
			return 0;
        	}
	}
}


void addStudent(Node* checkn, Node* addn) {
	//if anything else
	//if greater then next
	if (checkn->getNext() != NULL) {
		if (checkn->getNext()->getStudent()->getID() < addn->getStudent()->getID()) {
			addStudent(checkn->getNext(), addn);
			return;
		}	
	//if less then next
		else {
			addn->setNext(checkn->getNext());
		}
	}
	checkn->setNext(addn);
}
void printStudents(Node* n) {
	if (n == NULL) {
		return;
	}
	cout << setprecision(3);
	cout << n->getStudent()->getFirst() << " " << n->getStudent()->getLast() << " " << n->getStudent()->getID() << " " << n->getStudent()->getGPA() << endl; // output student info
	if (n->getNext() != NULL) {
		printStudents(n->getNext());
	}
}
	
void deleteStudent(Node* n, int sid, Node** head_ptr) {
	Node* temp = NULL;
	//list 0
	if (n == NULL) {
		return;
	}
	//if head ==
	if (n->getStudent()->getID() == sid) {
		if (n->getNext() == NULL) { // head = 1 long list
			delete n;
			*head_ptr = NULL;
			return;

		}
		else { // first of list
		        temp = n;
			*head_ptr = n->getNext();
			cout << "delete head" << endl;
			delete temp;
			cout << "returning head" << endl;
			return;
		}
	}
	else { // check next
		if (n->getNext() == NULL) {
			cout << "not in list" << endl;
			return;
		}
		if (n->getNext()->getStudent()->getID() == sid) {
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
	if (n == NULL) {
		return 0;
	}
	gpas = gpas + n->getStudent()->getGPA();
	total++;
	if (n->getNext() != NULL) {
		average(n->getNext(), gpas, total);
	}
	else {
		return (gpas / total);
	}

}


