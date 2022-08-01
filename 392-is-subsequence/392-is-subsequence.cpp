class Solution {
public:
    bool isSubsequence(string s, string t) {        
        int i = 0, n = s.length() , m = t.length() , j = 0;       
        while(i < m && j< n){
            if(s[j] == t[i]) j++;         
            i++;        
        }
        return j == n;
    }
};