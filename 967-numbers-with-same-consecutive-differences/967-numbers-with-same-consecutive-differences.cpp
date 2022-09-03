class Solution {
public:
    vector<int> ans;
    vector<int> numsSameConsecDiff(int n, int k) {
        /*
       //passing 66/81 test cases - giving TLE for n = 8 and above - my solution
        vector<int> ans;
        int start = 0;
        int end = 0 ;
        switch(n){ //make diff cases for number of digits
            case 2:
                start = 10;
                end = 99;
                break;
            case 3:
                start = 100;
                end =  999;
                break;
            case 4:
                start = 1000;
                end =  9999;
                break;
            case 5:
                start = 10000;
                end =  99999;
                break;
            case 6:
                start = 100000;
                end =  999999;
                break;
            case 7:
                start = 1000000;
                end =  9999999;
                break;
            case 8:
                start = 10000000;
                end =  99999999;
                break;
             case 9:
                start = 100000000;
                end =  999999999;
                break;
            
        }
        for(int i = start; i<=end; i++){
            if(is_diff(i,k)){ //check if the cons. digits have abs diff of k or not
                ans.push_back(i);
            }
        }
        return ans;
        
    }
    bool is_diff(int n, int k){
        int z = n%10; //last digit of the num
        n = n/10;
        while(n!=0){
            int x  = n%10;
            n = n/10;
            if(abs(z-x) != k){ // find diff
                return false;
                break;
            }
            z = x;//update z
        }
        return true;
        */
        
      //bfs approach
       for(int i = 1; i<10; i++){
           rcheck(i, k, n);
       }
        return ans;
    }
    void rcheck(int num, int k, int n){
        if(n==1) {
            ans.push_back(num); 
            return;
        }
        if(num%10-k>=0)rcheck(num*10+(num%10-k),k,n-1);
        if(k){if(num%10+k<10)rcheck(num*10+(num%10+k),k,n-1);}
    }
};