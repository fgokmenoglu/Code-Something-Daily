#include <iostream>
#include <climits>

// Class to represent a Min-Heap
class MinHeap {
	int* harr; // pointer to array of elements in min-heap
	int capacity; // maximum possible size of min-heap
	int hsize; // current number of elements in min-heap

public:
	MinHeap(int capacity);
	
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return 2 * i + 1; }
	int right(int i) { return 2 * i + 2; }

	void printHeap();
	void insertKey(int i);
	void deleteKey(int i);
	void decreaseKey(int i, int new_val);
	int extractMin();
	int getMin() { return harr[0]; }
	void MinHeapify(int i);
};

// Constructor
MinHeap::MinHeap(int cap) {
	hsize = 0;
	capacity = cap;
	harr = new int[cap];
}

// Print heap
void MinHeap::printHeap() {
	for (int i = 0; i < hsize; ++i)
		std::cout << harr[i] << " ";
	std::cout << "\n";
}

// Swap given two values
void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

// Insert a new key
void MinHeap::insertKey(int k) {
	if (hsize == capacity) {
		std::cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	// First insert the new key at the end
	int i = hsize++;
	harr[i] = k;

	// Fix the min heap property if it is violated
	while (i != 0 && harr[parent(i)] > harr[i]) {
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

// Heapify a subtree with the root at given index
void MinHeap::MinHeapify(int i) {
	int smallest = i;
	int left = this->left(i);
	int right = this->right(i);

	if (left < hsize && harr[left] < harr[smallest])
		smallest = left;

	if (right < hsize && harr[right] < harr[smallest])
		smallest = right;

	if (smallest != i) {
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}

// Update value of a given key
void MinHeap::decreaseKey(int i, int new_val) {
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] > harr[i]) {
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

// Extract the minimum value from the min-heap
int MinHeap::extractMin() {
	if (hsize <= 0)
		return INT_MIN;
	if (hsize == 1) {
		hsize--;
		return harr[0];
	}

	// Store the minimum value and remove it from heap
	int root = harr[0];
	harr[0] = harr[--hsize];
	MinHeapify(0);

	return root;
}

// Delete a key
void MinHeap::deleteKey(int i) {
	decreaseKey(i, INT_MIN);
	extractMin();
}

int main() {
	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);

	std::cout << "Min heap: ";
	h.printHeap();

	std::cout << "extracted min: " << h.extractMin() << "\n";
	std::cout << "min heap after extraction: ";
	h.printHeap();

	h.deleteKey(1);
	std::cout << "Min heap after deletion: ";
	h.printHeap();

	return 0;
}