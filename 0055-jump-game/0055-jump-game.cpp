class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goal = n-1;        
        for(int i = n-1 ; i > -1 ; i--){
            if(nums[i] + i - goal >= 0) goal = i;
        }
        return goal==0;
    }

};