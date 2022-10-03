class Solution {
public:
    int minCost(string s, vector<int>& nums) {
        int n = s.length();
        int i = 0 , ans = 0;
        
        while(i<n){
            char curr = s[i];
            int j = i;
            int maxi = 0 , sum = 0;
            while(j<n && s[j]==curr){
                sum+=nums[j];
                maxi = max(maxi , nums[j]);
                j++;
            }
            if(sum!=maxi) ans += sum-maxi;
            i = j;
        }
        
        return ans;
    }
};