/*
 * INTRODUCTION
 * Unless specified otherwise, every function argument is handled like a copy and does not change the original value. 
 * Depending on the size of your type, this can have serious consequences for the performance of your code.
 * References can be seen as aliases - changes to them have an effect on the original variable. 
 * References use an ampersand (&) in the type declaration.
 * Reseating (changing the binding of a reference) is not possible. 
 * You cannot have an uninitialized reference. 
 * References need to be initialized with an existing variable.
 * 
 * NOTES
 * With the power of references you might not need to return a value from a function at all. 
 * void is used as a return type in this scenario.
 */
#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};

// TODO: Task 1
// vote_count takes a reference to an `ElectionResult` as an argument and will
// return the number of votes in the `ElectionResult.
int vote_count(ElectionResult& result) {
    return result.votes;
}


// TODO: Task 2
// increment_vote_count takes a reference to an `ElectionResult` as an argument
// and a number of votes (int), and will increment the `ElectionResult` by that
// number of votes.
void increment_vote_count(ElectionResult& result, int votes) {
    result.votes += votes;
}


// TODO: Task 3
// determine_result receives the reference to a final_count and returns a
// reference to the `ElectionResult` of the new president. It also changes the
// name of the winner by prefixing it with "President". The final count is given
// in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
// `ElectionResults` of all the participating candidates.
ElectionResult& determine_result(std::vector<ElectionResult>& finalCount) {
    // Start with the first candidate as the potential winner
    ElectionResult* winner = &finalCount[0];

    // Iterate through the vector to find the candidate with the most votes
    for (auto& candidate : finalCount) {
        if (candidate.votes > winner->votes) {
            winner = &candidate;
        }
    }

    // Prefix the winner's name with "President "
    winner->name = "President " + winner->name;

    // Return a reference to the winner
    return *winner;
}

}  // namespace election
