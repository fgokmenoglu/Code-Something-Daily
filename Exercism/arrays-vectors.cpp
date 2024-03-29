/*
 * INTRODUCTION
 * C++ offers different containers to store elements of the same type in an ordered way. 
 * There is std::array for containers of a fixed size and std::vector, which comes with dynamic resizing capabilities.
 *
 * When you declare an array or a vector you need to specify the type of elements, that container will hold. 
 * Arrays also need a size. Look at these examples to see the two container types' initializations.
 * Vectors usually need more space, as they allocate memory for further growth. You do not need to specify a size.
 *
 * Vectors and arrays share the same functions to access their elements. 
 * You can use the member functions front and back to get the first and last elements of the container. 
 * There is also at and the [] operator to access specific elements.
 *
 * As a vector is not fixed in size, it is possible to add or remove elements. 
 * Two common functions for that purpose are emplace_back/push_back and pop_back.
 *
 * You can check the containers for emptiness with the member function empty. 
 * If you want to know the number of elements, you can use size.
 *
 * NOTES
 * If you pick a position that is not in the range of your container, [] might lead to undefined behavior. 
 * The at function would raise an exception, which might make your life easier in the long term.
 */

/*
 * TASK 1: Create the function round_down_scores() that takes a vector of student_scores. The schools' requested rounding is a truncation. 
 * Lucky for you, C++ can cast one type into another with static_cast. The static_cast conversion from double to int cuts off any digit after the decimal. 
 * This function should take the input vector and return a new vector with all the scores converted to ints.
 *
 * TASK 2: Create the function count_failed_students() that takes a vector of student_scores. 
 * This function should count up the number of students who don't have passing scores and return that count as an integer. 
 * A student needs a score greater than 40 to achieve a passing grade on the exam.
 *
 * TASK 3: Create the function above_threshold() taking student_scores (a vector of grades), and threshold (an int, the "top score" threshold) as parameters. 
 * This function should return a vector of all scores that are >= to threshold.
 *
 * TASK 4: Create the function letter_grades() that takes the "highest" score on the exam as a parameter, 
 * and returns an array (not a vector) of lower score thresholds for each "American style" grade interval: ["D", "C", "B", "A"].
 *
 * TASK 5: Create the function student_ranking() with parameters student_scores and student_names. 
 * Match each student name on the student_names vector with their score from the student_scores vector. 
 * You can assume each argument vector is sorted from highest score(er) to lowest score(er). 
 * The function should return a vector of strings with the format <rank>. <student name>: <student score>.
 *
 * TASK 6: Create the function perfect_score() with parameters student_scores and student_names. 
 * The lists are the same as in task 5. The function should return the first <name> (as a string) of the student who scored 100 on the exam.
 */
#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    // TODO: Implement round_down_scores
    std::vector<int> out = {};

    for (size_t i = 0; i < student_scores.size(); ++i)
        out.emplace_back(static_cast<int>(student_scores[i]));
    
    return out;
}


// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    // TODO: Implement count_failed_students
    int countFailed = 0;

    for (size_t i = 0; i < student_scores.size(); ++i)
        if (student_scores[i] <= 40)
            countFailed += 1;
    
    return countFailed;
}

// Determine how many of the provided student scores were 'the best' based on the provided threshold.
std::vector<int> above_threshold(std::vector<int> student_scores, int threshold) {
    // TODO: Implement above_threshold
    std::vector<int> out = {};

    for (size_t i = 0; i < student_scores.size(); ++i)
        if (student_scores[i] >= threshold)
            out.emplace_back(student_scores[i]);
    
    return out;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    // TODO: Implement letter_grades
    std::array<int, 4> thresholds;
    int range = highest_score - 40;
    int interval = range / 4;

    for (int i = 0; i < 4; ++i) {
        thresholds[i] = 41 + i * interval;
    }

    return thresholds;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(std::vector<int> student_scores, std::vector<std::string> student_names) {
    // TODO: Implement student_ranking
    std::vector<std::string> out = {};
    std::string temp = "";

    for (size_t i = 0; i < student_scores.size(); ++i) {
        temp = std::to_string(i + 1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]);
        out.emplace_back(temp);
    }
    
    return out;
}

// Create a string that contains the name of the first student to make a perfect score on the exam.
std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {
    // TODO: Implement perfect_score
    std::string out = "";

    for (size_t i = 0; i < student_scores.size(); ++i) {
        if (student_scores[i] == 100) {
            out = student_names[i];
            break;
        }
    }
    
    return out;
}
