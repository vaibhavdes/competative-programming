/*

Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
 NOTE : You may assume 1 <= k <= Total number of nodes in BST 

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
 
void find(TreeNode* A, int& small, int B, int& temp)
{
    if (!A)
        return;
    find(A->left, small, B, temp);
    ++temp;
    if (temp == B)
    {
        small = A->val;
        return;
    }
    find(A->right, small, B, temp);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    int small = -1;
    int temp = 0;
    find(A, small, B, temp);
    return small;
}
