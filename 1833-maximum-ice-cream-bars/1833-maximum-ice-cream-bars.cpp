class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin() , costs.end());
        int ans = 0 , i = 0 , n = costs.size();
        while(coins > 0 && i < n){
            int curr = costs[i];
            if(curr <= coins){
                ans++;
                coins -= curr;
                i++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};