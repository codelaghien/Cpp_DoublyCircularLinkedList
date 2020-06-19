// Cpp_DoublyCircularLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
 
#include <iostream>
#include "Node.h"
#include "DoublyCircularLinkedList.h"
using namespace std;

int main()
{
    cout << "Doubly Circular Linked List ! \n";
    cout << "----------------------------- \n";

    DoublyCircularLinkedList* list = new DoublyCircularLinkedList();
    list->insertNode(new Node(3), 0);
    list->insertNode(new Node(5), 1);
    list->insertNode(new Node(7), 20);
    list->insertNode(new Node(4), 2);
    list->printListNext();
    list->printListPrevious();

    int data = 30;
    cout << endl << "Sau khi xoa so: " << data << endl;
    list->deleteNode(data);
    list->printListNext();
    list->printListPrevious();

    cout << endl << endl << endl;
    system("PAUSE");
    return 0;
}
 