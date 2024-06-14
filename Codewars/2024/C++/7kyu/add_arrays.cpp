/*
 * Create a function called addArrays() that combines two arrays of equal length, 
 * summing each element of the first with the corresponding element in the second, returning the "combined" summed array.
 *
 * Note:
 * Expect array input to either contain numbers or strings only
 * The function should also allow for concatenating string
 * Raise an error if input arguments are not of equal length.
 *
 * addArrays([1,2],[4,5]); // => [5,7]
 * addArrays([1,2,3],[4,5]); // => Error
 * addArrays(["a"],["b"]) // => ["ab"]
 */
#include <vector>
#include <stdexcept>

template<class T>
std::vector<T> add_arrays(const std::vector<T>& array1, const std::vector<T>& array2) {
    if (array1.size() != array2.size())
        throw std::invalid_argument("Error");
  
    std::vector<T> out = {};
    
    for (size_t i = 0; i < array1.size(); i++)
        out.push_back(array1[i] + array2[i]);
  
    return out;
}
