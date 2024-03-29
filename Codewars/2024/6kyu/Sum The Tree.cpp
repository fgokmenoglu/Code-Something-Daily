/* Given a node object representing a binary tree:
 *
 * struct node {
 *   int value;
 *   node* left;
 *   node* right;
 * }
 *
 * Write a function that returns the sum of all values, including the root. 
 * Absence of a node will be indicated with a null value.
*/
int sumTheTreeValues(node* root) {
  if (root == nullptr) return 0;
 
  return root -> value + sumTheTreeValues(root -> left) + sumTheTreeValues(root -> right);
}
