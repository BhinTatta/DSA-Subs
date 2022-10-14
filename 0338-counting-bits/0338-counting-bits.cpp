class Solution {
public:
    int bits(int i){
        int ans = 0;
        while(i){
            ans += (i&1);
            i = i>>1;
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i = 0 ; i <= n ; i++){
            ans[i] = bits(i);
        }
        return ans;
    }
};