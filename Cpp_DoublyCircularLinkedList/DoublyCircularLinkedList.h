#pragma once
#include "Node.h"
using namespace std;

class DoublyCircularLinkedList
{ 
	private:
		int size = 0;

	public: 
		Node* start; 

	public:
		DoublyCircularLinkedList();
		~DoublyCircularLinkedList();

		int getSize();
		void printListPrevious();
		void printListNext();

		void insertNode(Node* node, int position);
		void deleteNode(int data);
		Node* searchNode(int data);
};

