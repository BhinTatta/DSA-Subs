class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int len = 0;
        for(int i = 0 ; i < n ; i++){
            int curr = nums[i];
            int lower = lower_bound(ans.begin(),ans.end(),curr) - ans.begin();
            if(lower==ans.size()){
                ans.push_back(curr);
            }
            else ans[lower_bound(ans.begin(),ans.end(),ans[lower]) - ans.begin()]=curr;
        }
        return ans.size();
    }
};