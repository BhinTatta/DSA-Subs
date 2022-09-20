class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        int l=0 , r = 0;
        int ans = 0;
        while(r<n){
            char curr = s[r];
            if(mp.find(curr)!=mp.end() && mp[curr]>=l){
                l = mp[curr]+1;
            }
            mp[curr]=r;
            ans = max(ans , r-l+1);
            r++;
        }
        return ans;
    }
};