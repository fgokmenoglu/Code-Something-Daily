/* DATA STRUCTURES */
/*
 * Data structures are ways of organizing and storing data so that they can be accessed and modified efficiently. 
 * They are fundamental components used to create efficient algorithms and systems. 
 * Different data structures are suited to different kinds of applications, and some are highly specialized to specific tasks.
 */

/* ARRAYS */
/* 
 * Always ensure that you do not access elements outside the bounds of the array.
 * Initialize your arrays to avoid undefined behavior.
 * Use meaningful names for your arrays to enhance code readability.
 */

/* VECTORS */
/*
 * Prefer vectors over arrays when the size of the array can change at runtime.
 * Use the at() function for element access to get automatic bounds checking.
 * Use reserve() if you know the approximate size in advance to avoid multiple reallocations.
 */

/* LINKED LISTS */
/*
 * They consist of nodes where each node contains data and a pointer to the next node in the sequence.
 * Carefully handle the head and tail pointers, especially in circular and doubly linked lists.
 * Ensure pointers are properly initialized and handled to avoid segmentation faults.
 * Always free the memory allocated for nodes to prevent memory leaks.
 */

/* STACKS */
/*
 * A stack is a linear data structure that follows the Last In First Out (LIFO) principle.
 *
 *
 */

#include <iostream>
#include <vector>

// Define the structure of a node (singly linked list)
struct Node {
	int data;
	Node* next;
};

// Function to print the linked list (singly linked list)
void printList(Node* n) {
	while (n != nullptr) {
		std::cout << n->data << " ";
		n = n->next;
	}
}

// Define the structure of a node (doubly linked list)
struct Node2 {
	int data;
	Node2* next;
	Node2* prev;
};

// Function to print the linked list (doubly linked list)
void printList2(Node2* n) {
	while (n != nullptr) {
		std::cout << n->data << " ";
		n = n->next;
	}
}

// Define the structure of a node (circular linked list)
struct Node3 {
	int data;
	Node3* next;
};

// Function to print the linked list (circular linked list)
void printList(Node3* head) {
	Node3* temp = head;

	if (head != nullptr) {
		do {
			std::cout << temp->data << " ";
			temp = temp->next;
		} while (temp != head);
	}
}

class Stack {
private:
	std::vector<int> stack;

public:
	bool isEmpty() {
		return stack.empty();
	}

	void push(int item) {
		stack.push_back(item);
		std::cout << item << " pushed to the stack." << std::endl;
	}

	int pop() {
		if (isEmpty()) {
			std::cout << "Stack underflow!" << std::endl;
			return INT_MIN;
		}

		int top = stack.back();
		stack.pop_back();
		
		return top;
	}

	int peek() {
		if (isEmpty()) {
			std::cout << "Stack is empty!" << std::endl;
			return INT_MIN;
		}

		return stack.back();
	}
};

class StackNode {
public:
	int data;
	StackNode* next;
};

StackNode* newNode(int data) {
	StackNode* stack_node = new StackNode();
	stack_node->data = data;
	stack_node->next = nullptr;

	return stack_node;
}

bool isEmpty(StackNode* root) {
	return !root;
}

void push(StackNode** root, int data) {
	StackNode* stack_node = newNode(data);
	stack_node->next = *root;
	*root = stack_node;
	std::cout << data << " pushed to the stack." << std::endl;
}

int pop(StackNode** root) {
	if (isEmpty(*root)) {
		std::cout << "Stack underflow!" << std::endl;
		return INT_MIN;
	}

	StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	delete temp;

	return popped;
}

int peek(StackNode* root) {
	if (isEmpty(root)) {
		std::cout << "Stack is empty!" << std::endl;
		return INT_MIN;
	}

	return root->data;
}

int main() {
	// One-dimensional Arrays
	int arr[5] = {1, 2, 3, 4, 5};

	for (int i = 0; i < 5; ++i) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;

	// Multi-dimensional Arrays
	int matrix[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			std::cout << matrix[i][j] << " ";
		}

		std::cout << std::endl;
	}

	// Vectors
	std::vector<int> vec;
    
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}

	std::cout << std::endl << "Removing the last element..." << std::endl;
	vec.pop_back();

	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}

	std::cout << std::endl;

	// Singly Linked List
	Node* head = nullptr;
	Node* second = nullptr;
	Node* third = nullptr;

	head = new Node();
	second = new Node();
	third = new Node();

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = nullptr;

	printList(head);

	delete head;
	delete second;
	delete third;

	std::cout << std::endl;

	// Doubly Linked List
	Node2* head2 = nullptr;
	Node2* second2 = nullptr;
	Node2* third2 = nullptr;

	head2 = new Node2();
	second2 = new Node2();
	third2 = new Node2();

	head2->data = 1;
	head2->next = second2;
	head2->prev = nullptr;

	second2->data = 2;
	second2->next = third2;
	second2->prev = head2;

	third2->data = 3;
	third2->next = nullptr;
	third2->prev = second2;

	printList2(head2);

	delete head2;
	delete second2;
	delete third2;

	std::cout << std::endl;

	// Circular Linked List
	Node3* head3 = nullptr;
	Node3* second3 = nullptr;
	Node3* third3 = nullptr;

	head3 = new Node3();
	second3 = new Node3();
	third3 = new Node3();

	head3->data = 1;
	head3->next = second3;

	second3->data = 2;
	second3->next = third3;

	third3->data = 3;
	third3->next = head3;

	printList(head3);

	delete head3;
	delete second3;
	delete third3;

	std::cout << std::endl;

	// Stack (using vectors)
	Stack stack;

	stack.push(1);
	stack.push(2);
	stack.push(3);

	std::cout << stack.pop() << " popped from stack" << std::endl;
	std::cout << "Top element is " << stack.peek() << std::endl;

	// Stack (using linked lists)
	StackNode* root = nullptr;

	push(&root, 1);
	push(&root, 2);
	push(&root, 3);

	std::cout << pop(&root) << " popped from stack" << std::endl;
	std::cout << "Top element is " << peek(root) << std::endl;

	std::cout << std::endl;

	return 0;
}