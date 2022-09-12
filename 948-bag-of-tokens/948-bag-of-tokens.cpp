class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int start=0, end= tokens.size()-1;
        int cscore=0; int mscore=0;
        while(start<=end)
        {
          if(power >= tokens[start]) 
          {  power -= tokens[start];
            cscore++;
            mscore=max(mscore, cscore);
            start++;}
            
            else if(cscore>=1){
                power += tokens[end];
            cscore --;
            end--;}
            else
                break;
        
        
        }
        
        return mscore;
        // sort(tokens.begin(), tokens.end());
        // int i = 0, j =  tokens.size()-1, score = 0, currscore = 0;
        // while(i<=j){
        //     if(power >= tokens[i]){
        //         power -= tokens[i];
        //         score = max(score, currscore);
        //         currscore++;
        //         i++;
        //     }
        //     else if(currscore>=1){
        //         power += tokens[j];
        //         currscore--;
        //         j--;
        //     }
        //     else{
        //         break;
        //     }
        // }
        // return score;
    }
};