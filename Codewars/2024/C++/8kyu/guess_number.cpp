#include <stdexcept>

/* Task Description:
 * Imagine you are creating a game where the user has to guess the correct number.
 * But there is a limit of how many guesses the user can do.
 *
 * If the user tries to guess more than the limit, the function should throw an error.
 * If the user guess is right it should return true.
 * If the user guess is wrong it should return false and lose a life.
 */

class Guesser
{
public:
    Guesser(int number, int lives)
      : number(number), lives(lives)
    { }
    
    bool guess(int n)
    {
        if (lives <= 0)
        {
            throw std::runtime_error("No more lives left");
        }
        
        if (n == number)
        {
            return true;
        }
        
        lives--;
        return false;
    }

private:
    int number, lives;
};
