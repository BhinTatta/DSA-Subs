class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        
        int maxlen = 0;
        int lpos = 0;
            
        for(int i = 0 ; i < n ; i++){
            int l = i , r = i;
            while(l >= 0 && r < n && s[l]==s[r]){
                if(r-l+1 > maxlen){
                    lpos = l;
                    maxlen = r-l+1;
                };
                l--;
                r++;
            }
            l = i , r = i+1;
            while(l >= 0 && r < n && s[l]==s[r]){
                if(r-l+1 > maxlen){
                    lpos = l;
                    maxlen = r-l+1;
                };
                l--;
                r++;
            }
        }
        
        string ans = s.substr(lpos,maxlen);
        cout<<maxlen;
        return ans;
    }
};