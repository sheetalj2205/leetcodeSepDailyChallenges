class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = 0;
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] % 2 == 0){
                evenSum += nums[i];
            }
        }
        int sum = evenSum;
        for(int i = 0; i<queries.size(); i++){
            if(nums[queries[i][1]] % 2 == 0){
                 sum -= nums[queries[i][1]];
            }
            nums[queries[i][1]] += queries[i][0];
            if( nums[queries[i][1]]%2 == 0){
                sum += nums[queries[i][1]];
            }
            
            ans.push_back(sum);
        }
        return ans;
    }
};