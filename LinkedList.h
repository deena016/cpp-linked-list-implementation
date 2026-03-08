#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/*
Node struct to manage a single element in a linked list.
*/

struct Node {
	int _data;
	Node *_next;
};

class LinkedList {
public:
    // Constructor, creates an empty list
	LinkedList();
    
    // Destructor, deletes all nodes in the list and sets head to nullptr
	~LinkedList();
	
    // Adds a node with the given data to the beginning of the list
	void AddNode(int data);
	
    // Prints the elements in the linked list
	void Print();
	
	Node* FindNode(int searchValue);
	bool DeleteValue(int deleteValue);
	bool InsertAfter(Node* existingNode, int newData);
private:
	Node *_head;
	
	/*
	The copy constructor and assignment operator are declared as
	private functions in order to make them inaccessible /
	uncallable.
	The rule of three mandates that if dynamic memory is used,
	the compiler-generated versions of the destructor, copy
	constructor, and assignment operator are not memory-safe.
	In this case, instead of implementing the copy constructor
	and assignment operator, we've disabled them so that the
	default (unsafe) versions are not inadvertently used.
	*/
    // Copy constructor: disabled
	LinkedList(const LinkedList &orig);
    // Assignment operator: disabled
	LinkedList &operator=(const LinkedList &rhs);
};
#endif
