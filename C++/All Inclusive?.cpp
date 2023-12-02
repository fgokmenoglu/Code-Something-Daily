/*
 * Input:
 * 
 * a string strng
 * an array of strings arr
 * Output of function contain_all_rots(strng, arr) (or containAllRots or contain-all-rots):
 * 
 * a boolean true if all rotations of strng are included in arr
 * false otherwise
 * Examples:
 * contain_all_rots(
 *   "bsjq", ["bsjq", "qbsj", "sjqb", "twZNsslC", "jqbs"]) -> true
 * 
 * contain_all_rots(
 *   "Ajylvpy", ["Ajylvpy", "ylvpyAj", "jylvpyA", "lvpyAjy", "pyAjylv", "vpyAjyl", "ipywee"]) -> false)
 * Note:
 * Though not correct in a mathematical sense
 * 
 * we will consider that there are no rotations of strng == ""
 * and for any array arr: contain_all_rots("", arr) --> true
 */
#include <string>
#include <vector>
#include <algorithm>

class Rotations {
  public:
    static bool containAllRots(const std::string &strng, std::vector<std::string> &arr) {
      if (strng == "")
        return true;
      
      int count = 0;
      
      for (size_t i = 0; i < strng.length(); i++) {
        std::string temp = strng;
        std::rotate(temp.begin(), temp.begin() + i, temp.end());
        
        if (std::find(arr.begin(), arr.end(), temp) != arr.end())
          count += 1;
      }
      
      return count == strng.length();
    }
};
