#include "Node.h"
//Functions to iterate through a linked list
Node::Node(Student* newstudent) {
  student = newstudent;
  next = NULL;
}
Node::~Node() {
  delete student;
  next = NULL;
}
Student* Node::getStudent() {
  return student;
}
void Node::setNext(Node* newnext) {
  next = newnext;
}
Node* Node::getNext() {
  return next;
}
