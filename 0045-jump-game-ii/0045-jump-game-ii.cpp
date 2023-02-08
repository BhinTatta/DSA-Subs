class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        
        int ans = 1 , i = 0;
        
        while(i < n-1){
            //cout<<i<<" ";
            int maxi = 0 , loc = 0;
            int len = nums[i];
            if(i+len >= n-1) break;
            
            for(int j = 1 ; j <= len ; j++){
                
                if(nums[i+j] + j > maxi){
                    maxi = nums[i+j] + j;
                    loc = i+j;
                }
            }
            i = loc;
            ans++;
        }
        
        return ans;
    }
};