#include "DoublyCircularLinkedList.h" 

DoublyCircularLinkedList::DoublyCircularLinkedList() {
	this->size = 0;
	this->start = NULL;
}
DoublyCircularLinkedList::~DoublyCircularLinkedList() { 
	while (this->start != NULL) {
		Node* currentNode = this->start;
		this->start = this->start->next;
		delete currentNode; 
	}
}
int DoublyCircularLinkedList::getSize() {
	return this->size; 
}
void DoublyCircularLinkedList::printListPrevious() {
	cout << "printListPrevious: " << endl;
	cout << "Size: " << this->size << endl;
	if (this->start == NULL) return;

	Node* currentNode = this->start->previous;
	int count = 0;
	while (currentNode != NULL && count < this->size) {
		currentNode->printData();
		cout << " ";
		currentNode = currentNode->previous;
		count++;
	}
	cout << endl;
}
void DoublyCircularLinkedList::printListNext() {
	cout << "printListNext: " << endl;
	cout << "Size: " << this->size << endl;
	if (this->start == NULL) return;

	Node* currentNode = this->start;
	int count = 0;
	while (currentNode != NULL && count < this->size) {
		currentNode->printData();
		cout << " ";
		currentNode = currentNode->next;
		count++;
	}
	cout << endl;
}
void DoublyCircularLinkedList::insertNode(Node* node, int position) {
	if (this->start == NULL) {
		this->start = node;
		this->start->next = this->start;
		this->start->previous = this->start;
		this->size++;
		return;
	}

	Node* currentNode = this->start;
	int count = 0;
	if (position > this->size) position = this->size;
	while (currentNode != NULL && count < position) {
		currentNode = currentNode->next;
		count++;
	}
	if (currentNode != NULL) {
		if (currentNode->previous != NULL) currentNode->previous->next = node;
		node->next = currentNode;
		node->previous = currentNode->previous;
		currentNode->previous = node;
		this->size++;
	} 
}
void DoublyCircularLinkedList::deleteNode(int data) {
	if (this->start == NULL) return;

	Node* currentNode = this->start;
	int count = 0; 
	while (currentNode != NULL && count < this->size) {
		if (currentNode->data == data) {
			currentNode->previous->next = currentNode->next;
			currentNode->previous->next->previous = currentNode->previous;
			this->size--;
			if (count == 0) {
				this->start = this->start->next;
			}
			delete currentNode; 
			return;
		}
		currentNode = currentNode->next;
		count++;
	} 
}
Node* DoublyCircularLinkedList::searchNode(int data) {
	if (this->start == NULL) {
		cout << "Khong tim ra data (" << data << ")" << endl;
		return NULL;
	}

	Node* currentNode = this->start;
	int count = 0;
	while (currentNode != NULL && count < this->size) {
		if (currentNode->data == data) {
			return currentNode;
		}
		currentNode = currentNode->next;
		count++;
	}

	cout << "Khong tim ra data (" << data << ")" << endl;
	return NULL;
}
