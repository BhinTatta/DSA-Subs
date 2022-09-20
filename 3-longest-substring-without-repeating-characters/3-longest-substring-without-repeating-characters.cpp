class Solution {
public:
    
    bool okay(vector<int> &nums){
        for(auto i : nums) if(i>1) return false;
        return true;
    }
    
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        vector<int> mp(300,0);
        
        int l = 0, r = 0;
        while(r<n){
            int pos = s[r];
            mp[pos]++;
            while(l<r && !okay(mp)){
                int lpos = s[l];
                mp[lpos]--;
                l++;
            }
            ans = max(ans , r-l+1);
            r++;
        }
        
        return ans;

    }
};