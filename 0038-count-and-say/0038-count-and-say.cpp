class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string ans = "1";
        
        for(int i = 2 ; i <= n ; i++){
            string str = helper(ans);
            ans = str;
        }
        return ans;
    }
    
    string helper(string &s){
        string ans = "";
        int n = s.length() , i = 0;
        while(i<n){
            int j = i+1;
            char curr = s[i];
            while(j<n && s[j]==curr) j++;
            int len = j-i;
            ans.push_back('0' + len);
            ans.push_back(curr);
            i = j;
        }
        return ans;
    }
};