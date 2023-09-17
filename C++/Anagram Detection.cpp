#include <string>

bool isAnagram(std::string test, std::string original){
  if (test.length() != original.length())
    return false;
  
  std::transform(test.begin(), test.end(), test.begin(), ::tolower);
  // std::cout << test << std::endl;
  std::transform(original.begin(), original.end(), original.begin(), ::tolower);
  // std::cout << original << std::endl;
  
  for (char& c : test)
    if (original.find(c) == std::string::npos) {
      // std::cout << c << std::endl;
      return false;
    }
  
  return true;
}

#include <string>

bool isAnagram(std::string t, std::string o){

 if(t.size() != o.size())
  return false;
  
  std::transform(t.begin(),t.end(),t.begin(),::tolower);
  std::transform(o.begin(),o.end(),o.begin(),::tolower);
  std::sort(t.begin(),t.end());
  std::sort(o.begin(),o.end());
  
  return t==o;
  
}
