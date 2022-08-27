class Solution {
public:
    int titleToNumber(string col) {
        long long int ans = 0;
        for(int i = col.length()-1 ; i > -1 ; i--){
            char curr = col[i];
            ans += pow(26,col.length()-i-1) * (curr-'A'+1);
        }
        return ans;
    }
};