/*
Kids drink toddy.
Teens drink coke.
Young adults drink beer.
Adults drink whisky.
Make a function that receive age, and return what they drink.

Rules:

Children under 14 old.
Teens under 18 old.
Young under 21 old.
Adults have 21 or more.
Examples: (Input --> Output)

13 --> "drink toddy"
17 --> "drink coke"
18 --> "drink beer"
20 --> "drink beer"
30 --> "drink whisky"
*/
function peopleWithAgeDrink(old) {
  if (old >= 21)
    return "drink whisky";
  else if (old >= 18)
    return "drink beer";
  else if (old >= 14)
    return "drink coke";
  else
    return "drink toddy";
};

// ALTERNATIVE USING ARROW FUNCTIONS
/*
const peopleWithAgeDrink = (age) =>
  age < 14 ? "drink toddy" :
  age < 18 ? "drink coke" :
  age < 21 ? "drink beer" : "drink whisky"
*/
