class Solution {
public:
    int maxlen , req_sum;
    vector<vector<int>> combinationSum3(int dig, int req) {
        maxlen = dig;
        req_sum = req;
        
        vector<vector<int>> ans;
        vector<int>temp;
        solver(ans,temp , req_sum , 0 , 1 );
        return ans;
    }
    
    void solver(vector<vector<int>> &ans ,vector<int>temp, int sum , int curr_len, int i){
        if(curr_len == maxlen && sum==0){
            ans.push_back(temp);
            return;
        }
        if(curr_len > maxlen || i > 9) return;
        
        if(i <= sum){
            solver(ans,temp,sum,curr_len,i+1);
            temp.push_back(i);
            solver(ans,temp,sum-i,curr_len+1,i+1);
        }
        else{
            solver(ans,temp,sum,curr_len,i+1);
        }        
        
    }
};