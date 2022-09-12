class Solution {
public:
    int bagOfTokensScore(vector<int>& nums, int power) {
        sort(nums.begin() , nums.end() );
        int n = nums.size();
        int l = 0 , r = n-1;
        int score = 0 , ans = 0;
        
        while(l<=r){
            //int curr = nums[];  
            if(power>=nums[l]){
                power-=nums[l];
                score++;
                l++;
                ans = max(ans , score);
            }
            
            else if(score>0){
                power += nums[r];
                score--;
                r--;
            }
            else break;
            
        }
        
        return ans;
    }
};