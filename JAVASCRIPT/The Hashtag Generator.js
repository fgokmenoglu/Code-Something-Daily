/*
The marketing team is spending way too much time typing in hashtags.
Let's help them with our own Hashtag Generator!

Here's the deal:

It must start with a hashtag (#).
All words must have their first letter capitalized.
If the final result is longer than 140 chars it must return false.
If the input or the result is an empty string it must return false.
Examples
" Hello there thanks for trying my Kata"  =>  "#HelloThereThanksForTryingMyKata"
"    Hello     World   "                  =>  "#HelloWorld"
""                                        =>  false
*/
function generateHashtag (str) {
  // str = str.replace(/\s/g,'');
  
  if (str.length == 0)
    return false;
  
  str = str.split(' ');
  // console.log(str);
  
  for (var i = 0; i < str.length; i++) {
    if (str[i].length > 0)
      str[i] = str[i][0].toUpperCase() + str[i].substr(1);
  }
  
  str = str.join('');
  
  if (str.length > 139 || str.length == 0)
    return false;
  
  return '#' + str;
}

// ALTERNATIVE USING REDUCE
/*
function generateHashtag (str) {

  var hashtag = str.split(' ').reduce(function(tag, word) {
    return tag + word.charAt(0).toUpperCase() + word.substring(1);
  }, '#');
  
  return hashtag.length == 1 || hashtag.length > 140 ? false : hashtag;
}
*/

/*
A string representing the character (exactly one UTF-16 code unit) at the specified index. 
If index is out of the range of 0 – str.length - 1, charAt() returns an empty string.
*/
