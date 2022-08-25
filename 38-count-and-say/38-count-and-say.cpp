class Solution {
public:
    string countAndSay(int n) {
        string ans;
        ans = helper(n);
        return ans;
    }
    
    string helper(int n){
        if(n==1) return "1";
        
        string prev = helper(n-1);
        string ans = "";
        int i = 0 , m = prev.length();
        while(i<m){
            char dig = prev[i];
            int count = 0;
            while(i<m && prev[i]==dig){
                count++;
                i++;
            }
            ans += to_string(count);
            ans+= dig;
        }
        //cout<<ans<<endl;
        return ans;
    }
};