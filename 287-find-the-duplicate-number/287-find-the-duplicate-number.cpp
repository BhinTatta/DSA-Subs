class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0 , fast = 0;
        int move = 0;
        
        while(slow!=fast || move==0){
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
            move = 1;
        }
        
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};