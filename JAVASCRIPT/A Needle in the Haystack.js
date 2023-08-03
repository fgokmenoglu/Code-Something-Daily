/*
Can you find the needle in the haystack?

Write a function findNeedle() that takes an array full of junk but containing one "needle"

After your function finds the needle it should return a message (as a string) that says:

"found the needle at position " plus the index it found the needle, so:

Example(Input --> Output)

["hay", "junk", "hay", "hay", "moreJunk", "needle", "randomJunk"] --> "found the needle at position 5" 
*/
function findNeedle(haystack) {
  return "found the needle at position " + haystack.findIndex((element) => element == "needle");
}

/*
The find() method returns the first element in the provided array that satisfies the provided testing function. If no values satisfy the testing function, undefined is returned.
If you need the index of the found element in the array, use findIndex().
If you need to find the index of a value, use indexOf(). (It's similar to findIndex(), but checks each element for equality with the value instead of using a testing function.)
If you need to find if a value exists in an array, use includes(). Again, it checks each element for equality with the value instead of using a testing function.
*/
