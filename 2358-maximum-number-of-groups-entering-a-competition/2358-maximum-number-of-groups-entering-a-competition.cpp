class Solution {
public:
    int maximumGroups(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int ans = 0;
        
        int n = nums.size() , pre = 1;
        while(n>0 && n>=pre){
            ans++;
            n -= pre;
            pre++;
        }
        
        return ans;
    }
};