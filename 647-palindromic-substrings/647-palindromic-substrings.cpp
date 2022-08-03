class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        
        int ans = 0;
        
        for(int i = 0 ; i < n ; i ++){
            int l = i , r = i;           
            while(l >= 0 && r<n && s[l]==s[r]){
                ans++;
                r++;
                l--;
            }
            l = i , r = i+1;
            while(l >= 0 && r<n && s[l]==s[r]){
                ans++;
                r++;
                l--;
            }
            
        }
        
        return ans;
    }
};