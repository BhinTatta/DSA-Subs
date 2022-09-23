class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        if(n==1) return 1;
        
        int l = 0 , r = 1;
        int ans = 1 , currlen = 0;
        
        while(r<n){
            if(s[r]-s[r-1] != 1) l = r;
            else{
                ans = max(ans , r-l+1);
            }
            r++;
        }
        return ans;
    }
};