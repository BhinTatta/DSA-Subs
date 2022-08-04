class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int jumps = 0;
        int l = 0 , r = 0;
        
        while(r < n-1){
            int reach = 0;
            for(int i = l; i <= r; i++){
                reach = max(reach , i+nums[i]);
            }
            l = r+1;
            r = reach;
            jumps++;
        }
        
        return jumps;
    }

};