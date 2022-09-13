class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        
        int buy1 = INT_MAX , buy2 = buy1;
        int profit1 = INT_MIN , profit2 = INT_MIN;
        
        for(int i = 0 ; i < n ; i++){
            buy1 = min(buy1 , nums[i]);
            profit1 = max(profit1 , nums[i]-buy1);
            buy2 = min(buy2 , nums[i]-profit1);
            profit2 = max(profit2 , nums[i]-buy2);
        }
        
        return profit2;
    }
};