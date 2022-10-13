class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i<n){
            if(nums[i]!=0){
                i++;
                continue;
            }
            int j = i+1;
            while(j<n && nums[j]==0)j++;
            if(j<n) swap(nums[i],nums[j]);
            i++;
        }
    }
};