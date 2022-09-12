class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        //first sort the array
        sort(tokens.begin(), tokens.end());
        //take two variables to find max score
        int i = 0, j =  tokens.size()-1, score = 0, currscore = 0;
        //take two pointers one from end and start
        while(i<=j){
            if(power >= tokens[i]){ 
                power -= tokens[i];
                currscore++;
                score = max(score, currscore); //store max score in score
                i++;
            }
            else if(currscore>=1){
                power += tokens[j];
                j--;
                currscore--; //decrease currscore
            }
            else{
                break; //if score<1 and power < tokens[i] then break
            }
        }
        return score;
    }
};