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
     vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL){
            return ans;
        }
        stack<TreeNode*> q;
        TreeNode* node = root;
        while(true){
            if(node!= NULL){
                q.push(node);
                node = node->left;
            }
            else{
                if(q.empty()) break;
                node = q.top();
                q.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        // inorderTraversal(root->left);
        // ans.push_back(root->val);
        // inorderTraversal(root->right);
        return ans;
    }
};