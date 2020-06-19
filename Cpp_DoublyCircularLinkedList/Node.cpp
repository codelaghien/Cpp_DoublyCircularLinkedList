#include "Node.h"

Node::Node(int data) { 
	this->data = data;
	this->previous = NULL;
	this->next = NULL;
}
Node::~Node() {
}
void Node::printData() {
	cout << this->data;
}
