/*
 * Your task is to write function factorial.
 */
long long factorial(int n) {
  if (n == 1 || n == 0)
    return 1;
  else
    return n * factorial(n - 1);
}

// ALTERNATIVE
long long factorial(int n) {
  return n == 0 ? 1 : n * factorial(n - 1);
}
