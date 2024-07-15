/*
 * We have the Pascal's triangle, horizontal lines are numbered from zero (top). 
 * We want to calculate the sum of the squares of the binomial coefficients 
 * on a given horizontal line with a function called easyline.
 * 
 * Can you write a program which calculate easyline(n) where n is the horizontal line number?
 * The function will take n (with: n>= 0) as parameter and will return the sum of the squares of the binomial coefficients on line n.
 *
 * Examples:
 * easyline(0) => 1
 * easyline(1) => 2
 * easyline(4) => 70
 * easyline(50) => 100891344545564193334812497256
 *
 * Note:
 * In Javascript, Coffeescript, Typescript, C++, PHP, C, R, Nim, Fortran to get around the fact that we have no big integers the function easyLine(n) will in fact return
 * round(log(easyline(n)))
 * and not the easyline(n) of the other languages.
 * So, in Javascript, Coffeescript, Typescript, C++, PHP, R, Nim, C, Fortran:
 * easyLine(0) => 0
 * easyLine(1) => 1
 * easyLine(4) => 4
 * easyLine(50) => 67
 */
#include <vector>
#include <cmath>

class EasyLine
{
public:
    static long long easyLine(int n) {
        if (n == 0) return 0;
        
        std::vector<double> line(n + 1, 0);
        line[0] = line[n] = 0; // log(1) = 0
        
        for (int i = 1; i <= n / 2; ++i) {
            line[i] = line[n - i] = line[i - 1] + log(n - i + 1) - log(i);
        }
        
        double sum = 0;
        for (int i = 0; i <= n; ++i) {
            sum += exp(2 * line[i]);
        }
        
        return std::round(log(sum));
    }
};
