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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        vector<vector<int>> levelOrder;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            double avg = 0;
            for(int i = 0; i<n; i++){
                TreeNode* nod = q.front();
                q.pop();
                avg += nod->val;
                if(nod->left){
                q.push(nod->left);
                }
                if(nod->right){
                q.push(nod->right);
                }
            }
            ans.push_back(double(avg/n));
            
        }
        return ans;
    }
};