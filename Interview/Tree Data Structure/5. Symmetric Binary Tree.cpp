/*

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :

    1
   / \
  2   2
 / \ / \
3  4 4  3
The above binary tree is symmetric.
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool isSymmetricHelper(TreeNode *leftTree, TreeNode *rightTree) {
      if (leftTree == NULL || rightTree == NULL) 
        return leftTree == rightTree;
        
      if (leftTree->val != rightTree->val) 
        return 0;
        
      return isSymmetricHelper(leftTree->left, rightTree->right) && isSymmetricHelper(leftTree->right, rightTree->left);
}
bool Solution::isSymmetric(TreeNode *A) {
    return A == NULL || isSymmetricHelper(A->left, A->right);
}
