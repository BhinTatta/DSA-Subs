class Solution {
public:
    vector<int> helper(int n){
        vector<int> ans;
        int i = 0;
        while(n){
            if(n&1){
                ans.push_back(pow(2,i));
            }
            i++;
            n/=2;
        }
        return ans;
    }
    
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power = helper(n);
        vector<int> ans;
        
        int mod = 1e9 + 7;
        for(auto it : queries){
            int a = it[0] , b = it[1];
            long long int curr = 1;
            for(int i = a ; i <= b ; i++){
                curr *= power[i];
                curr = curr%mod;
            }
            ans.push_back(curr%mod);
        }
        return ans;
    }
};