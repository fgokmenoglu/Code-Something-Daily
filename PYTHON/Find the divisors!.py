"""
Create a function named divisors/Divisors that takes an integer n > 1 and returns an array with all of the integer's divisors(except for 1 and the number itself), from smallest to largest. If the number is prime return the string '(integer) is prime' (null in C#) (use Either String a in Haskell and Result<Vec<u32>, String> in Rust).

Example:
divisors(12); #should return [2,3,4,6]
divisors(25); #should return [5]
divisors(13); #should return "13 is prime"
"""
def divisors(integer):
    result = [i for i in range(2, integer) if integer % i == 0] # Next time check up until 'sqrt(integer)'
    
    if len(result) == 0:
        return f"{integer} is prime"
    
    return result
