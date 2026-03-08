#include "LinkedList.h"
#include <cassert>
#include <iostream>
using namespace std;

int main() {
	LinkedList list;
	list.Print();
	for (int i = 5; i > 0; i--) {
		list.AddNode(i);
	}
	list.Print();
	cout << "Setup complete." << endl << endl;
	
	
	cout << "Test: find node with value 3" << endl;
	Node *found = list.FindNode(3);
	cout << "Found: " << found->_data << endl;
	assert(found->_data == 3 && found->_next != nullptr);
	list.Print();
	cout << endl;
	
	cout << "Test: find node with value 5" << endl;
	found = list.FindNode(5);
	cout << "Found: " << found->_data << endl;
	assert(found->_data == 5 && found->_next == nullptr);
	list.Print();
	cout << endl;
	
	cout << "Test: find node with value 1" << endl;
	found = list.FindNode(1);
	assert(found->_data == 1 && found->_next != nullptr);
	cout << "Found: " << found->_data << endl;
	list.Print();
	cout << endl;
	
	cout << "Test: find node with value 7 (not in list)" << endl;
	found = list.FindNode(7);
	assert(found == nullptr);
	list.Print();
	cout << endl;
	
	
	
	cout << "Test: delete node from middle of list" << endl;
	bool deleted = list.DeleteValue(4);
	assert(deleted);
	list.Print();
	cout << endl;
	
	cout << "Test: delete node from end of list" << endl;
	deleted = list.DeleteValue(5);
	assert(deleted);
	list.Print();
	cout << endl;
	
	cout << "Test: delete node from front of list" << endl;
	deleted = list.DeleteValue(1);
	assert(deleted);
	list.Print();
	cout << endl;
	
	cout << "Test: delete element not in list" << endl;
	deleted = list.DeleteValue(7);
	assert(!deleted);
	list.Print();
	cout << endl;
	
	
	cout << "Test: insert element into middle" << endl;
	found = list.FindNode(2);
	assert(found != nullptr);
	list.InsertAfter(found, 10);
	list.Print();
	cout << endl;
	
	cout << "Test: insert element at end" << endl;
	found = list.FindNode(3);
	assert(found != nullptr);
	list.InsertAfter(found, 14);
	list.Print();
	cout << endl;
	
	cout << "Test: delete all elements" << endl;
	deleted = list.DeleteValue(2);
	assert(deleted);
	deleted = list.DeleteValue(3);
	assert(deleted);
	deleted = list.DeleteValue(10);
	assert(deleted);
	deleted = list.DeleteValue(14);
	assert(deleted);
	list.Print();
	cout << endl;
	
	cout << "Test: add node after deleting all" << endl;
	list.AddNode(27);
	list.Print();
	cout << endl;
	
}
