class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(auto i : s){
            if(st.empty()) st.push(i);
            else if(st.top()==i)st.pop();
            else st.push(i);
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};