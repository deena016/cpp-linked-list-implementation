#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
	this->_head = nullptr;
}

LinkedList::~LinkedList() {
	while (_head != nullptr) {
		Node *nextNode = _head->_next;
		delete _head;
		_head = nextNode;
	}
}

void LinkedList::AddNode(int data) {
	Node *newNode = new Node{data, this->_head};
	this->_head = newNode;
}

void LinkedList::Print() {
	Node *nodeToPrint = _head;
	cout << "{";
	while (nodeToPrint != nullptr) {
		cout << nodeToPrint->_data << " -> ";
		nodeToPrint = nodeToPrint->_next;
	}
	cout << ".}" << endl;
}

// Finds and returns a pointer to the first node whose data matches searchValue,
// Returns nullptr if the value is not found.
Node* LinkedList::FindNode(int searchValue) {
    // Start searching from the head of the list
    Node* current = _head;

    // Traverse the list until we reach the end
    while (current != nullptr) {
        // Check if the current node contains the search value
        if (current->_data == searchValue) {
            return current; // Node found
        }
        // Move to the next node
        current = current->_next;
    }
    
    // Value not found in the list
    return nullptr;
}

// Deletes the first node that contains deleteValue.
// Returns true if deletion was successful, false otherwise.
bool LinkedList::DeleteValue(int deleteValue) {
    // Case 1: empty list
    if (_head == nullptr) {
        return false;
    }

    // Case 2: delete head
    if (_head->_data == deleteValue) {
        Node* temp = _head; // Store old head
        _head = _head->_next; // Move head to next node
        delete temp; // Free memory
        return true;
    }

    // Case 3: delete middle or end
    Node* current = _head;
    // Look ahead to find the node before the one to delete
    while (current->_next != nullptr) {
        if (current->_next->_data == deleteValue) {
            Node* temp = current->_next;      // Node to delete
            current->_next = temp->_next;     // Reconnect list
            delete temp;                      // Free memory
            return true;
        }
        // Move to the next node
        current = current->_next;
    }

    // Value not found in the list
    return false;
}

// Inserts a new node with value newData immediately after existingNode.
// Returns true if insertion is successful, false if existingNode is not
//in the list.
bool LinkedList::InsertAfter(Node* existingNode, int newData) {
    // Cannot insert after a null pointer
    if (existingNode == nullptr) {
        return false;
    }

    // Start traversal from the head
    Node* current = _head;

    // Search for the existingNode in the list
    while (current != nullptr) {
        if (current == existingNode) {
            // Create new node and link it into the list
            Node* newNode = new Node{newData, current->_next};
            current->_next = newNode;
            return true;
        }
        // Move to the next node
        current = current->_next;
    }
    
    // existingNode was not found in this list
    return false;
}



