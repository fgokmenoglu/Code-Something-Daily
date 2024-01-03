/*
 * Now that the competition gets tough it will Sort out the men from the boys. Men are the Even numbers and Boys are the odd.
 * 
 * Task
 * Given an array/list [] of n integers , Separate The even numbers from the odds , or Separate the men from the boys
 *
 * Notes
 * Return an array/list where Even numbers come first then odds
 * Since , Men are stronger than Boys , Then Even numbers in ascending order While odds in descending .
 * Array/list size is at least 4 .
 * Array/list numbers could be a mixture of positives , negatives .
 * Have no fear , It is guaranteed that no Zeroes will exists .!alt
 * Repetition of numbers in the array/list could occur , So (duplications are not included when separating).
 * 
 * Input >> Output Examples:
 * menFromBoys ({7, 3 , 14 , 17}) ==> return ({14, 17, 7, 3}) 
 *
 * Explanation:
 * Since , { 14 } is the even number here , So it came first , then the odds in descending order {17 , 7 , 3} .
 */
#include <vector>
#include <functional> // for greater<int>()
#include <algorithm> // for sort(), unique(), copy()

using namespace std; 

vector<int> menFromBoys (vector<int> values) {
  vector<int> evenMen = {};
  vector<int> oddBoys = {};
  vector<int> result = {};
  
  for (size_t i = 0; i < values.size(); i++)
    if (values[i] % 2 == 0)
      evenMen.push_back(values[i]);
    else
      oddBoys.push_back(values[i]);     
  
  sort(evenMen.begin(), evenMen.end());
  evenMen.erase(unique(evenMen.begin(), evenMen.end()), evenMen.end());
  
  sort(oddBoys.begin(), oddBoys.end(), greater<int>());
  oddBoys.erase(unique(oddBoys.begin(), oddBoys.end()), oddBoys.end());
  
  std::copy(evenMen.begin(), evenMen.end(), std::back_inserter(result));
  std::copy(oddBoys.begin(), oddBoys.end(), std::back_inserter(result));
  
  return result;
}

// ALTERNATIVE
#include <vector>
#include <functional> // for greater<int>()
#include <algorithm> // for partition(), sort(), unique()

std::vector<int> menFromBoys(std::vector<int> values)
{
    auto it = std::partition(begin(values), end(values), [](auto n) {return n % 2 == 0;});
    std::sort(begin(values), it);
    std::sort(it, end(values), std::greater<>());
    values.erase(std::unique(begin(values), end(values)), end(values));
    return values;
}

// partition() reorders the elements in the range [first, last) in such a way that all elements for which the predicate p returns true precede the elements for which predicate p returns false. 
// Iterator to the first element of the second group.
