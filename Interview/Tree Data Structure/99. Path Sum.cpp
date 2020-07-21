/*

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Example :

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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
 
 int pathsum(TreeNode* root, int sum)
{
    if(!root->left && !root->right)
    {
        if(sum==root->val)
            return 1;
        else
            return 0;
    }
    int x = 0, y = 0;
    if(root->left)
        x = pathsum(root->left, sum - root->val);
    if(root->right)
        y = pathsum(root->right, sum - root->val);
        
    return x || y;
}

 
 int Solution::hasPathSum(TreeNode* A, int B) {
    if (!A && !B)
        return 0;
    return pathsum(A,B);
}
