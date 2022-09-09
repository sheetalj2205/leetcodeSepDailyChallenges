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
    bool isSorted(vector<int> inOrder){
        for(int i = 1; i<inOrder.size(); i++){
            if(inOrder[i-1] >= inOrder[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> ans;
    bool inorderTrav(TreeNode* root){
        if(!root){
            return true;
        }
        stack<TreeNode*> q;
        TreeNode* node = root;
        while(true){
            if(node != NULL){
                q.push(node);
                node = node->left;
            }
            else{
                if(q.empty()) break;
                node = q.top();
                q.pop();
                ans.push_back(node->val);
                node=node->right;
            }
        }
        if(isSorted(ans)){
            return true;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return inorderTrav(root);
    }
};