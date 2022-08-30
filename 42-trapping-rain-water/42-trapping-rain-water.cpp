class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return 0;
        int ans = 0;
        int l = 1 , r = n-2;
        int lmax = nums[0] , rmax = nums[n-1];
        
        while(l<=r){
            
            int left = nums[l], right = nums[r];
            
            if(lmax <= rmax){
                if(left>lmax){
                    lmax = left;
                }
                else{
                    ans += lmax-left;
                }
                l++;
            }
            
            else if(lmax > rmax){
                if(right > rmax){
                    rmax = right;
                }
                else{
                    ans += rmax-right;
                }
                r--;
            }
            //cout<<ans<<endl;
        }
        
        return ans;
    }
};