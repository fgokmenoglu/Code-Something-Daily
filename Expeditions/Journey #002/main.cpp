#include <string>
#include <iostream>

// Structure to keep student information
struct Student {
    int ID;
    std::string name;
    double GPA;

    // Default constructor
    Student() : ID(0), name(""), GPA(0.0) {}
    
    // Parameterized constructor
    Student(int id, std::string n, double gpa) : ID(id), name(n), GPA(gpa) {}
};

Student* createStudentRecords(int num_students) {
    return new Student[num_students];
}

void populateStudentRecords(Student* student_records, int num_students) {
    for (auto i = 0; i < num_students; ++i) {
        std::cout << "Enter a student ID: ";
        std::cin >> student_records[i].ID;
        std::cin.ignore(); // Ignore the newline character left in the input buffer

        std::cout << "Enter the student name: ";
        std::getline(std::cin, student_records[i].name); // Use getline to read names with spaces

        std::cout << "Enter the student GPA: ";
        std::cin >> student_records[i].GPA;
    }
}

void displayStudentRecords(Student* student_records, int num_students) {
    for (auto i = 0; i < num_students; ++i) {
        std::cout << "Student[" << i + 1 << "]\t"
            << "ID: " << student_records[i].ID << "\t"
            << "Name: " << student_records[i].name << "\t"
            << "GPA: " << student_records[i].GPA << std::endl;
    }
}

Student* findStudentById(Student* student_records, int num_students, int student_ID) {
    for (auto i = 0; i < num_students; ++i) {
        if (student_records[i].ID == student_ID) {
            return &student_records[i];
        }
    }

    std::cerr << "Could not find a student for the given ID..." << std::endl;
    return nullptr;
}

void modifyStudentGPA(Student* student_records, int num_students, int student_ID, double new_GPA) {
    Student* student = findStudentById(student_records, num_students, student_ID);

    if (student != nullptr) {
        student->GPA = new_GPA;
    }
    else {
        std::cerr << "Student with ID " << student_ID << " not found to modify GPA." << std::endl;
    }
}

Student* deleteStudent(Student* student_records, int& num_students, int student_ID) {
    int index = -1;
    for (int i = 0; i < num_students; ++i) {
        if (student_records[i].ID == student_ID) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        std::cerr << "Student with ID " << student_ID << " not found to delete." << std::endl;
        return student_records;
    }

    // Create a new array with one less element
    Student* new_records = new Student[num_students - 1];
    for (int i = 0, j = 0; i < num_students; i++) {
        if (i != index) {
            new_records[j++] = student_records[i];
        }
    }

    // Free the old array
    delete[] student_records;
    num_students--;

    return new_records;
}

int main() {
    // Prompt user to specify how many students they want to enter information
    int num_students;
    std::cout << "Enter the number of students: ";
    std::cin >> num_students;
    std::cin.ignore(); // To ignore the newline left in the input buffer

    // Create an empty record array
    Student* student_records = createStudentRecords(num_students);

    // Populate the array with student records
    populateStudentRecords(student_records, num_students);

    // Display the student records
    displayStudentRecords(student_records, num_students);

    // Provide an example for modifyStudentGPA method
    int student_ID;
    double new_GPA;

    std::cout << "Enter the ID of the student to modify GPA: ";
    std::cin >> student_ID;
    std::cout << "Enter new GPA: ";
    std::cin >> new_GPA;

    modifyStudentGPA(student_records, num_students, student_ID, new_GPA);

    // Display the updated records
    std::cout << "After GPA modification:" << std::endl;
    displayStudentRecords(student_records, num_students);

    // Provide an example for deleteStudent method
    std::cout << "Enter the ID of the student to delete: ";
    std::cin >> student_ID;
    student_records = deleteStudent(student_records, num_students, student_ID);

    // Display the updated records
    std::cout << "After deleting the student:" << std::endl;
    displayStudentRecords(student_records, num_students);

    // Free allocated memory
    delete[] student_records;

    return 0;
}
