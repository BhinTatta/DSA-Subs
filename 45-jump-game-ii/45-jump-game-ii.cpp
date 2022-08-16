class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int ans = 1;
        int i = 0;
        
        while(i<n-1){
            int len = nums[i];
            if(i+len >= n-1) break;
            int reach = 0;
            int pos = 0;
            for(int j = 1 ; j <= len ; j++){
                if(j+i < n){
                    if(nums[j+i]+j > reach){
                        reach = nums[j+i] + j;
                        pos = i+j;
                    }
                }
            }
            ans++;
            if(reach >= n-1) break;
            i = pos;        
        }
        return ans;
    }
};