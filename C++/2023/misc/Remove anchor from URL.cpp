/*
 * Complete the function/method so that it returns the url with anything after the anchor (#) removed.
 * 
 * Examples
 * "www.codewars.com#about" --> "www.codewars.com"
 * "www.codewars.com?page=1" -->"www.codewars.com?page=1"
 */
std::string replaceAll(std::string str) {
  return str.substr(0, str.find('#'));
}
