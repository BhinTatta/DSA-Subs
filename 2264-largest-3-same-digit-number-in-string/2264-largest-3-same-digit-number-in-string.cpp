class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        int i = 0;
        string ans = "";
        while(i<n-2){
            if(num[i]==num[i+1] && num[i]==num[i+2]){
                ans = max(ans , num.substr(i,3));
            }
            i++;
        }
        return ans;
    }
};