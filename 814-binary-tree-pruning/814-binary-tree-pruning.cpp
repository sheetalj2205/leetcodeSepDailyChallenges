/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        root->left = pruneTree(root->left); //go to extreme left
        root->right = pruneTree(root->right); // go to the extreme right
        if(!root->left && !root->right && (root->val == 0)){ //check if the node's left and right child is null and val is 0 then return NULL
            return NULL;
        }
        return root;
    }
};