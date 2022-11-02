class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int a = 0, b = 0;
        
        for(int i = n-2 ; i >= 0 ; i--){
            if(nums[i]<nums[i+1]){
                a = i;
                break;
            }
        }
        
        for(int i = n-1 ; i >= 0 ; i--){
            if(nums[i]>nums[a]){
                b = i;
                break;
            }
        }
        
        if(a!=b) swap(nums[a] , nums[b]);
        if(a==0 && b==0) reverse(nums.begin() , nums.end());
        else reverse(nums.begin()+a+1 , nums.end());

    }
};