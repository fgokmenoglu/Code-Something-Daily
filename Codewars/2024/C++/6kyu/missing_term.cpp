/*
 * An Arithmetic Progression is defined as one in which 
 * there is a constant difference between 
 * the consecutive terms of a given series of numbers. 
 * You are provided with consecutive elements of an Arithmetic Progression. 
 * There is however one hitch: exactly one term from 
 * the original series is missing from the set of numbers 
 * which have been given to you. 
 * The rest of the given series is the same as the original AP. 
 * Find the missing term.
 *
 * You have to write a function that receives a list, 
 * list size will always be at least 3 numbers. 
 * The missing term will never be the first or last one.
 *
 * Example
 * findMissing([1, 3, 5, 9, 11]) == 7
 */
static long findMissing(std::vector<long> list) {
    int n = list.size();
    long d = (list[n-1] - list[0]) / n;
    for (int i = 1; i < n; i++) {
        if (list[i] - list[i-1] != d) {
            return list[i-1] + d;
        }
    }
}
