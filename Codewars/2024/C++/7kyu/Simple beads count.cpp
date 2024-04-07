/* 
 * Two red beads are placed between every two blue beads. 
 * There are N blue beads. Work out the number of red beads.
 */
unsigned int countRedBeads(unsigned int n) {
  return n >=2 ? 2 * n - 2 : 0;
}
