/*
 * Description:
 * 
 * We want to generate a function that computes the series starting from 0 and ending until the given number.
 * 
 * Example:
 * Input:
 * 
 * > 6
 * Output:
 *
 * 0+1+2+3+4+5+6 = 21
 */
using namespace std;

class SequenceSum{
  int count;
  public:
  SequenceSum (int);
  string showSequence();
  
};

string SequenceSum::showSequence() {
  int sum = 0;
  string output = "";
  
  if (count == 0)
    return "0=0";
  
  if (count < 0)
    return to_string(count) + "<0";
  
  for (auto i = 0; i <= count; i++) {
    sum += i;
    output += to_string(i) + '+';
  }
  
  output.pop_back();
  output += " = " + to_string(sum);

  return output;  
}

SequenceSum::SequenceSum (int c) {
  count = c;
}

// ALTERNATIVE
// A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin). 
// To use stringstream, we need to include sstream header file. The stringstream class is extremely useful in parsing input.
string SequenceSum::showSequence() {
  if (count < 0) return to_string(count) + "<0";
  
  if (!count) return "0=0";
  
  stringstream ss; 
  ss << 0;
    
  for (int i = 1; i <= count; ++i)
    ss << '+' << i;
  
  ss << " = " << count * (count + 1) / 2;
  return ss.str();
}
