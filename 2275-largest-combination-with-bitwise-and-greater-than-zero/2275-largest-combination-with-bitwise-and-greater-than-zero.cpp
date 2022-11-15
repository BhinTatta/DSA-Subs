class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int bit[32];
        memset(bit,0,sizeof(bit));
        
        for(int i = 0 ; i < 32 ; i++){
            for(int curr : candidates){
                if(curr & (1<<i)) bit[i]++;
            }
        }
        
        int ans  = 0;
        for(int i = 0 ; i < 32 ; i++){
            ans = max(ans , bit[i]);
        }
        return ans;
    }
};