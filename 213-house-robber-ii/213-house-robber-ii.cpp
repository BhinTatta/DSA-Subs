class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp1( n+1 , 0);
        vector<int> dp2( n+1 , 0);
        //start from n-1 and exlude pos=0
        dp1[1]=nums[0];
        for(int i = 1; i < n-1; i++){
            dp1[i+1] = max(nums[i]+dp1[i-1] , dp1[i]);
        }
        dp2[1]=nums[1];
        for(int i = 1 ; i < n-1 ; i++){
            dp2[i+1] = max(nums[i+1]+dp2[i-1] , dp2[i]);
        }
        
        int x = dp1[n-1];
        int y = dp2[n-1];
        return max(x , y);
    }
    
};