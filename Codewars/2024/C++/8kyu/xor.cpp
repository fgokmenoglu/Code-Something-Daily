/*
 * Your task is to define a function xor(a, b) where a and b are the two expressions to be evaluated. 
 * Your xor function should return true if exactly one of the two expressions evaluate to true, false otherwise.
 */
bool xorf(bool a, bool b) {
  return (a || b) && !(a && b);
  // return a xor b;
  // return a ^ b;
}
