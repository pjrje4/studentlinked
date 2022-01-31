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
void deleteStudent(Node* n, int sid);

int main() {
	Node* head = NULL;
	while (true) { //loop
		char input[20];
		cout << "Enter a command (ADD, PRINT, DELETE, QUIT): ";
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
			deleteStudent(head, stoi(input));
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
	cout << setprecision(2);
	cout << n->getStudent()->getFirst() << " " << n->getStudent()->getLast() << " " << n->getStudent()->getID() << " " << n->getStudent()->getGPA() << endl; // output student info
	if (n->getNext() != NULL) {
		printStudents(n->getNext());
	}
}
	
void deleteStudent(Node* n, int sid) {
	//list 0
	if (n == NULL) {
		return;
	}
	//if head ==
	if (n->getStudent()->getID() == sid) {
		if (n->getNext() == NULL) { // head = 1 long list
			n = NULL;
		}
		else { // first of list
			Node* tempHead = n;
			n = n->getNext();
			delete tempHead;
		}
	}
	else { // check next
		if (n->getNext() == NULL) {
			return;
		}
		if (n->getNext()->getStudent()->getID() == sid) {
			//end of list
			if (n->getNext()->getNext() == NULL) {
				Node* nTemp = n->getNext();
				n->setNext(NULL);
				delete nTemp;
				return;
			}
			// middle of list
			else {
				Node* nTemp = n->getNext();
				n->setNext(n->getNext()->getNext());
				delete nTemp;
				return;
			}
		}
		else {
			// recurse
			deleteStudent(n->getNext(), sid);
			return;
		}
	}
}
		



