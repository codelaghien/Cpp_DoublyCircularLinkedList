#pragma once
#include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* previous = NULL;
		Node* next = NULL;
		 
	public:
		Node(int data);
		~Node();

		void printData();
};

