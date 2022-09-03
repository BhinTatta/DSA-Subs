class Solution {
public:
    vector<int> ans; 
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 0 ; i < 10 ; i++){
            helper(n , k , 1 , i , i);
        }
        return ans;
    }
    
    void helper(int n , int k , int len , int dig , long long curr){
        if(len==n){
            ans.push_back(curr);
            return;
        }
        //cout<<curr<<endl;
        for(int i = 0 ; i < 10 ; i++){
            if(len==n-1 && i==0) continue;
            if( abs(i - dig) == k){
                long long newcurr = curr + (i*pow(10,len));
                helper(n , k , len+1 , i , newcurr);
            }
        }
        
    }
};