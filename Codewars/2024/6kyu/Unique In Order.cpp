/*
 * Implement the function unique_in_order which takes as argument a sequence 
 * and returns a list of items without any elements 
 * with the same value next to each other 
 * and preserving the original order of elements.
 *
 * For example:
 *
 * uniqueInOrder("AAAABBBCCDAABBB") == {'A', 'B', 'C', 'D', 'A', 'B'}
 * uniqueInOrder("ABBCcAD")         == {'A', 'B', 'C', 'c', 'A', 'D'}
 * uniqueInOrder([1,2,2,3,3])       == {1,2,3}
 */
#include <string>
#include <vector>

template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable) {
  std::vector<T> out{};
  out.push_back(iterable[0]);
  
  for (size_t i = 1; i < iterable.size(); ++i)
    if (iterable[i] != iterable[i - 1])
      out.push_back(iterable[i]);
  
  return out;
}

std::vector<char> uniqueInOrder(const std::string& iterable) {
  if (iterable == "")
    return {};
  
  std::vector<char> out{};
  out.push_back(iterable[0]);
  
  for (size_t i = 1; i < iterable.size(); ++i)
    if (iterable[i] != iterable[i - 1])
      out.push_back(iterable[i]);
  
  return out;
}

// ALTERNATIVE
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable) {
    vector<T> res;
    unique_copy(iterable.begin(), iterable.end(), std::back_inserter(res));
    return res;
}

std::vector<char> uniqueInOrder(const std::string& iterable) {
    vector<char> res;
    unique_copy(iterable.begin(), iterable.end(), std::back_inserter(res));
    return res;
}
