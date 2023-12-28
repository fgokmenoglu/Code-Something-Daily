/*
 * Being a bald man myself, I know the feeling of needing to keep it clean shaven. Nothing worse that a stray hair waving in the wind.
 * 
 * You will be given a string(x). Clean shaved head is shown as "-" and stray hairs are shown as "/". Your task is to check the head for stray hairs and get rid of them.
 * 
 * You should return the original string, but with any stray hairs removed. Keep count ot them though, as there is a second element you need to return:
 * 
 * 0 hairs --> "Clean!"
 * 1 hair --> "Unicorn!"
 * 2 hairs --> "Homer!"
 * 3-5 hairs --> "Careless!"
 * >5 hairs --> "Hobo!"
 * 
 * So for this head: "------/------" you shoud return:
 * 
 * ["-------------", "Unicorn"]
 */
#include <string>
#include <utility>

std::pair<std::string, std::string> bald(const std::string& s) {
  int count = 0;
  
  for (size_t i = 0; i < s.length(); ++i)
    if (s[i] == '/')
      count += 1;

  switch (count) {
    case 0: return {std::string(s.length(), '-'), "Clean!"};
    case 1: return {std::string(s.length(), '-'), "Unicorn!"};
    case 2: return {std::string(s.length(), '-'), "Homer!"};
    case 3 ... 5: return {std::string(s.length(), '-'), "Careless!"};
    default: return {std::string(s.length(), '-'), "Hobo!"};
  }
}

// ALTERNATIVE
#include <string>
#include <utility>

std::pair<std::string, std::string> bald(const std::string& s) {
  size_t n = std::count(s.begin(), s.end(), '/');
  std::string r;
  
  switch (n) {
    case 0  : r = "Clean!"; break;
    case 1  : r = "Unicorn!"; break;
    case 2  : r = "Homer!"; break;
    case 3  :
    case 4  :
    case 5  : r = "Careless!"; break;
    default : r = "Hobo!";
  }
  
  return {std::string(s.size(), '-'), r};
}

// ALTERNATIVE 2
#include <string>
#include <utility>

std::pair<std::string, std::string> bald(std::string s, int c = 0) {
	std::transform(s.begin(), s.end(), s.begin(), [&](char x) { if (x == '/') ++c; return '-'; });
	return { s, c == 0 ? "Clean!" : c == 1 ? "Unicorn!" : c == 2 ? "Homer!" : c <= 5 ? "Careless!" : "Hobo!" };
}
