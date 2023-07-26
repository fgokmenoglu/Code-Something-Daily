/*
Given a string of words, you need to find the highest scoring word.

Each letter of a word scores points according to its position in the alphabet: a = 1, b = 2, c = 3 etc.

For example, the score of abad is 8 (1 + 2 + 1 + 4).

You need to return the highest scoring word as a string.

If two words score the same, return the word that appears earliest in the original string.

All letters will be lowercase and all inputs will be valid.
*/
letter_value = {
  'a' : 1,
  'b' : 2,
  'c' : 3,
  'd' : 4,
  'e' : 5,
  'f' : 6,
  'g' : 7,
  'h' : 8,
  'i' : 9,  
  'j' : 10,
  'k' : 11,
  'l' : 12,
  'm' : 13,
  'n' : 14,  
  'o' : 15,
  'p' : 16,
  'q' : 17,
  'r' : 18,
  's' : 19,  
  't' : 20,
  'u' : 21,
  'v' : 22,
  'w' : 23,
  'x' : 24,  
  'y' : 25,
  'z' : 26,
};

function high(x){
  winner = '';
  max_score = 0;
  
  words = x.split(' ');
  // console.log(words);
  
  for (var i = 0; i < words.length; i++) {
    temp = words[i].split('');
    // console.log(temp);

    current_score = 0;
    
    for (var j = 0; j < temp.length; j++) {
      current_score += letter_value[temp[j]];
      
      if (current_score > max_score) {
        max_score = current_score;
        winner = words[i];
      }
    }
  }
  
  return winner;
}

// ALTERNATIVE
// let word_scores = x.split(' ').map(words => [...words].reduce((a, b) => a + b.charCodeAt(0) - 96, 0));
// return x.split(' ')[word_scores.indexOf(Math.max(...word_scores))];
