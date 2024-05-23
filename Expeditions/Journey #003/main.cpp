/*
 * Templates and Generic Programming in C++
 *
 * Templates in C++ allow you to write generic and reusable code. 
 * They enable functions and classes to operate with generic types, 
 * making them more flexible and type-safe.
 */

/*
 * Function templates define a blueprint for functions that 
 * can operate with any data type.
 */
#include <iostream>

template <typename T>
T add(T a, T b) {
	return a + b;
}

/*
 * Class templates allow the creation of generic classes.
 */
template <typename T>
class Box {
private:
	T value;
public:
	Box(T val) : value(val) {}
	T getValue() {
		return value;
	}
};

/*
 * Template specialization allows customization of template code 
 * for specific types.
 */
template <typename T>
class Printer {
public:
	void print(T value) {
		std::cout << value << std::endl;
	}
};

// Specialization for char*
template <>
class Printer<char*> {
public:
	void print(const char* value) {
		std::cout << "String: " << value << std::endl;
	}
};

/*
 * Templates can have type parameters, 
 * non-type parametes (e.g. integers), 
 * even other templates as parameters.
 */
template <typename T, int size>
class Array {
private:
	T arr[size];
public:
	T& operator[](int index) {
		return arr[index];
	}
};

/*
 * Variadic templates allow templates 
 * to accept a variable number of arguments.
 */
template <typename... Args>
void print(Args... args) {
	(std::cout << ... << args) << std::endl;
}

int main() {
	// function templates example
	// std::cout << "int: " << add(3, 4) << std::endl;
	// std::cout << "double: " << add(3.2, 4.5) << std::endl;

	// class templates examples
	// Box<int> int_box(123);
	// Box<std::string> str_box("Yay templates!");
	// std::cout << "int Box: " << int_box.getValue() << std::endl;
	// std::cout << "string Box: " << str_box.getValue() << std::endl;

	// Printer<int> int_printer;
	// Printer<char*> str_printer;
	// int_printer.print(123);
	// str_printer.print("Yay template specialization!");

	// Array<int, 5> int_array;
	// int_array[0] = 10;
	// std::cout << int_array[0] << std::endl;

	print(1, 2.5, "Yay variadic templates!");

	return 0;
}

/*
 * Final Notes:
 * Templates enable the creation of data structures that can work with any data type. 
 * This flexibility is crucial for writing reusable and efficient code.
 * Example: The std::vector in the STL is a template-based class that can store any type of data.
 * 
 * The STL provides a range of template - based containers like std::vector, std::list, std::map, and std::set.
 * These containers are implemented using templates, making them versatile and efficient.
 * 
 * Templates allow the creation of generic algorithms that work with any data type and container.
 * Example: std::sort works with any container that provides iterators, such as std::vector or std::array.
 */
