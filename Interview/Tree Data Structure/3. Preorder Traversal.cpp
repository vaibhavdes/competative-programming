/*

Given a binary tree, return the preorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,2,3].

Using recursion is not allowed.

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
 
 vector<int> preorderTraversal(TreeNode *A) {
    vector<int> res;
    stack<TreeNode*> nodeStack;

    while (nodeStack.size() != 0 || A != NULL) {
        if(A == NULL) {
            A = nodeStack.top();
            nodeStack.pop();
        } else {
            res.push_back(A->val);
            if(A->right != NULL)
                nodeStack.push(A->right);
            A = A->left;
        }
    }
    return res;
}
