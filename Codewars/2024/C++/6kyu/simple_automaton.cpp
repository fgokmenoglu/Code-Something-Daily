/**
 * @file Automaton.cpp
 * @brief Implementation of a simple finite automaton.
 *
 * This file contains the implementation of a finite automaton that accepts
 * the language of A, defined as {0, 1}. The automaton has three states:
 * q1 (start state), q2 (accept state), and q3.
 *
 * State transitions:
 * - q1 moves to q2 when given a 1, and stays at q1 when given a 0
 * - q2 moves to q3 when given a 0, and stays at q2 when given a 1
 * - q3 moves to q2 when given a 0 or 1
 *
 * The automaton returns whether it ends in the accepted state (q2) or not.
 */

#include <vector>
#include <functional>

/**
 * @class Automaton
 * @brief Represents a finite automaton with three states.
 *
 * This class implements the finite automaton described above using
 * a functional approach with lambda functions to represent state transitions.
 */
class Automaton {
private:
    using StateFunction = std::function<int(char)>;
    std::vector<StateFunction> states;
    int current_state;

public:
    /**
     * @brief Constructs the Automaton with predefined state transitions.
     */
    Automaton() : current_state(0) {
        // q1 state (index 0)
        states.push_back([](char input) -> int {
            return input == '1' ? 1 : 0;
        });

        // q2 state (index 1)
        states.push_back([](char input) -> int {
            return input == '0' ? 2 : 1;
        });

        // q3 state (index 2)
        states.push_back([](char) -> int {
            return 1;
        });
    }

    /**
     * @brief Processes a sequence of commands through the automaton.
     * @param commands A vector of characters representing the input sequence.
     * @return true if the automaton ends in the accept state (q2), false otherwise.
     */
    bool read_commands(const std::vector<char>& commands) {
        for (char c : commands) {
            current_state = states[current_state](c);
        }
        bool result = (current_state == 1);  // q2 is the accept state
        current_state = 0;  // Reset to initial state
        return result;
    }
};

// ALTERNATIVE
/**
 * @file Automaton.cpp
 * @brief Implementation of a simple finite automaton.
 *
 * This file contains the implementation of a finite automaton that accepts
 * the language of A, defined as {0, 1}. The automaton has three states:
 * q1 (start state), q2 (accept state), and q3.
 *
 * State transitions:
 * - q1 moves to q2 when given a 1, and stays at q1 when given a 0
 * - q2 moves to q3 when given a 0, and stays at q2 when given a 1
 * - q3 moves to q2 when given a 0 or 1
 *
 * The automaton returns whether it ends in the accepted state (q2) or not.
 */

#include <vector>

// Forward declarations
class State;
class Q1;
class Q2;
class Q3;

/**
 * @class State
 * @brief Abstract base class for automaton states.
 */
class State {
public:
    virtual State* transition(char input) = 0;
    virtual bool isAccept() const = 0;
    virtual ~State() = default;
};

/**
 * @class Q1
 * @brief Represents the start state (q1) of the automaton.
 */
class Q1 : public State {
public:
    State* transition(char input) override;
    bool isAccept() const override { return false; }
};

/**
 * @class Q2
 * @brief Represents the accept state (q2) of the automaton.
 */
class Q2 : public State {
public:
    State* transition(char input) override;
    bool isAccept() const override { return true; }
};

/**
 * @class Q3
 * @brief Represents the third state (q3) of the automaton.
 */
class Q3 : public State {
public:
    State* transition(char input) override;
    bool isAccept() const override { return false; }
};

// Implement transition functions
State* Q1::transition(char input) {
    return input == '1' ? static_cast<State*>(new Q2()) : this;
}

State* Q2::transition(char input) {
    return input == '0' ? static_cast<State*>(new Q3()) : this;
}

State* Q3::transition(char input) {
    (void)input; // Suppress unused parameter warning
    return static_cast<State*>(new Q2());
}

/**
 * @class Automaton
 * @brief Represents the finite automaton with three states.
 *
 * This class manages the current state and processes input commands
 * according to the automaton's rules.
 */
class Automaton {
private:
    State* current_state;

public:
    /**
     * @brief Constructs the Automaton with q1 as the initial state.
     */
    Automaton() : current_state(new Q1()) {}

    /**
     * @brief Processes a sequence of commands through the automaton.
     * @param commands A vector of characters representing the input sequence.
     * @return true if the automaton ends in the accept state (q2), false otherwise.
     */
    bool read_commands(const std::vector<char>& commands) {
        for (char c : commands) {
            State* next_state = current_state->transition(c);
            if (next_state != current_state) {
                delete current_state;
                current_state = next_state;
            }
        }
        bool result = current_state->isAccept();
        delete current_state;
        current_state = new Q1();
        return result;
    }

    /**
     * @brief Destructor to ensure proper cleanup of dynamically allocated states.
     */
    ~Automaton() {
        delete current_state;
    }
};
