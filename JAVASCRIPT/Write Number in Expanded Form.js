/*
You will be given a number and you will need to return it as a string in Expanded Form. For example:

expandedForm(12); // Should return '10 + 2'
expandedForm(42); // Should return '40 + 2'
expandedForm(70304); // Should return '70000 + 300 + 4'

NOTE: All numbers will be whole numbers greater than 0.
*/
function expandedForm(num) {
  digits = [];
  
  while (num > 0) {
    digits.push(num % 10);
    num = Math.floor(num / 10);
  }
  
  for (let i = 0; i < digits.length; i++)
    digits[i] = digits[i] * (10 ** i);
  
  digits = digits.filter((d) => d !=0);
  digits = digits.reverse();
  // console.log(digits);
  
  result = digits.join(' + '); 
  // console.log(result);
  
  return result;
}

// ALTERNATIVE
/*
const expandedForm = num => num.toString()
                            .split('')
                            .reverse()
                            .map((d, i) => d * Math.pow(10, i))
                            .filter(d => d > 0)
                            .reverse()
                            .join(' + ');
*/
