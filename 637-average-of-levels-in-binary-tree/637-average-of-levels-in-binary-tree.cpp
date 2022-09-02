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
    //same as level order traversal question
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q; //take queue
        q.push(root);
        while(!q.empty()){ //run the loop till q is not empty
            int n = q.size();
            double avg = 0;
            for(int i = 0; i<n; i++){ //run the loop for the curr size of the queue
                TreeNode* nod = q.front(); //take front node
                q.pop(); 
                avg += nod->val; //add its value to the sum
                if(nod->left){
                q.push(nod->left);
                }
                if(nod->right){
                q.push(nod->right);
                }
            }
            ans.push_back(double(avg/n)); //add the avg value in the array
            
        }
        return ans;
    }
};