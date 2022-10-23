class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1,0);
        
        for(int i : nums){
            freq[i]++;
        }
        vector<int> ans;
        int twice , miss;
        for(int i = 1 ; i <= n ; i++){
            int x = freq[i];
            if(x==0 ) miss = i;
            if(x==2) twice = i;
        }
        
        return {twice,miss};
    }
};