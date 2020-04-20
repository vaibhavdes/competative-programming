/*
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

 

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

          8
   5          10
1     7           12
 

Note: 

1 <= preorder.length <= 100
The values of preorder are distinct.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        struct TreeNode* root, *node;
        root = NULL;
        for(int i = 0; i < preorder.size(); i++) {
            node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
            node-> val = preorder[i];
            node-> left = NULL;
            node-> right = NULL;
            if(root == NULL) 
                root = node;
            else {
                struct TreeNode* cur, *ptr;
                cur = root;
                while(cur) {
                    ptr = cur;
                    if(cur->val > node->val)
                        cur = cur->left;
                    else
                        cur = cur->right;
                }
                if(node->val > ptr->val)
                    ptr->right = node;
                else
                    ptr->left = node;
            }                
        }        
        return root;
    }
};
