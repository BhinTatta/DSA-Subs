class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int n = prices.size();
        int prof = 0;
        
        while(r<n){
            //prof = max(prices[r] - prices[l] , prof);
            if(prices[r] < prices[l]){
                l=r;
            }
            prof = max(prices[r] - prices[l] , prof);
            r++;
        }
        
        return prof;
    }
};