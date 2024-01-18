/*
 * INTRODUCTION
 * Loops are used to repeatedly execute some logic. 
 * The two most common types are the while loop (indefinite looping) and the for loop (definite, or counted looping). 
 * There is also the for each loop.
 *
 * The for loop consists of a header and a code block that contains the body of the loop wrapped in curly brackets. 
 * The header consists of 3 components separated by semicolons ;: init-statement, condition, and another expression. Each of these may be empty.
 * The while loop executes its body as long as its condition check is true.
 *
 * When working with loops it is often required to add 1 or subtract 1 from a counter variable which keeps track of the iterations. 
 * This is so common, that the incrementing/decrementing actions have special operators: ++ and --.
 * They come in a prefix and a postfix form. 
 * The prefix changes the variable before use in the statement and the postfix version afterward. 
 * You probably want the prefix version most of the time.
 *
 * Inside a loop body, you can use the break keyword to stop the execution of the loop entirely.
 * In contrast, the keyword continue only stops the execution of the current iteration and continues with the next one.
 */

/*
 * TASK 1: Implement the interest_rate function to calculate the interest rate based on the specified balance.
 * TASK 2: Implement the yearly_interest function to calculate the interest based on the specified balance.
 * TASK 3: Implement the annual_balance_update function to calculate the annual balance update, taking into account the interest rate.
 * TASK 4: Implement the years_until_desired_balance function to calculate the minimum number of years required to reach the desired balance, 
 * taking into account that each year, interest is added to the balance. 
 * This means that the balance after one year is: start balance + interest for start balance. 
 * The balance after the second year is the balance after one year interest for the balance after one year. 
 * And so on, until the current year's balance is greater than or equal to the target balance.
 */

// interest_rate returns the interest rate for the provided balance.
double interest_rate(double balance) {
    // TODO: Implement the interest_rate function
    double interestRate = 0.0;
    
    if (balance < 0)
        interestRate = 3.213;
    else if (balance >= 0 && balance < 1000)
        interestRate = 0.5;
    else if (balance >= 1000 && balance < 5000)
        interestRate = 1.621;
    else
        interestRate = 2.475;
        
    return interestRate;
}

// yearly_interest calculates the yearly interest for the provided balance.
double yearly_interest(double balance) {
    // TODO: Implement the yearly_interest function
    return balance * interest_rate(balance) / 100;
}

// annual_balance_update calculates the annual balance update, taking into
// account the interest rate.
double annual_balance_update(double balance) {
    // TODO: Implement the annual_balance_update function
    return balance + yearly_interest(balance);
}

// years_until_desired_balance calculates the minimum number of years required
// to reach the desired balance.
int years_until_desired_balance(double balance, double target_balance) {
    // TODO: Implement the years_until_desired_balance function
    int yearsUntil = 0;
    
    while (balance < target_balance) {
        balance = annual_balance_update(balance);
        yearsUntil += 1;
    }
    
    return yearsUntil;
}
