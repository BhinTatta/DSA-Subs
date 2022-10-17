class Solution {
public:
    bool checkIfPangram(string sentence) {
        int dp[26];
        memset(dp,0,sizeof(dp));
        for(char i : sentence){
            dp[i-'a']++;
        }
        for(int i = 0 ; i < 26 ; i++) if(dp[i]==0) return false;
        return true;
    }
};