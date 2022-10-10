class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.size();
        if(n==1) return "";
        
        if(n&1 == 0){
            int i = 0;
            while(i<n && s[i]=='a') i++;
            if(i!=n) s[i]='a';
            else s[n-1] = 'b';
            return s;
        }
        else{
            int i = 0;
            while(i<n && s[i]=='a') i++;
            if(i!=n && i!=(n/2)) s[i] = 'a';
            else s[n-1] = 'b';
            return s;
        }
        return "";
    }
};