class Solution {
public:
    string removeOuterParentheses(string s) {
        int num = 0;
        string ans = "";
        for(auto c : s){
            if(c=='('){
                if(num){
                    ans+=c;
                }
                num++;
            }
            else{
                if(num>1){
                    ans+=c;
                }
                num--;
            }
        }
        return ans;
    }
};