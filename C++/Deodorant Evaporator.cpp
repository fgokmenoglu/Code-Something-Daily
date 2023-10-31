/*
 * This program tests the life of an evaporator containing a gas.
 * 
 * We know the content of the evaporator (content in ml), the percentage of foam or gas lost every day (evap_per_day) 
 * and the threshold (threshold) in percentage beyond which the evaporator is no longer useful. 
 * All numbers are strictly positive.
 * 
 * The program reports the nth day (as an integer) on which the evaporator will be out of use.
 * 
 * Example:
 * evaporator(10, 10, 5) -> 29
 * Note:
 * Content is in fact not necessary in the body of the function "evaporator", you can use it or not use it, as you wish. 
 * Some people might prefer to reason with content, some other with percentages only. 
 * It's up to you but you must keep it as a parameter because the tests have it as an argument.
 */
using namespace std;

class Evaporator
{

  public:
    static int evaporator(double content, double evap_per_day, double threshold) {
      int nth_day = 0;
      double remaining = content;
      
      while (remaining >= content * (threshold / 100)) {
        remaining -= remaining * (evap_per_day / 100);
        nth_day += 1;
      }
      
      return nth_day;
    }
};

// ALTERNATIVE
#include <cmath>

using namespace std;
class Evaporator
{

  public:
  static int evaporator(double content, double evap_per_day, double threshold);
};

int Evaporator::evaporator(double content, double evap_per_day, double threshold)
{
  // Finding N in (1.0-evap_per_day) to the N is less than threshold
  // Which is logarithm of threshold in base (1.0-evap_per_day), rounded up
  // C++ stdlib doesn't give you arbitrary log, but log of N in base B == logN/logB for any base
  // Also, don't forget that the percentages are being given as read (i.e. 10) not real numbers (0.1)
  return ceil(log(threshold / 100.0) / log(1.0 - (evap_per_day / 100.0)));
}
