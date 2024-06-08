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
#include <iostream>
#include <vector>

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

	return 0;
}