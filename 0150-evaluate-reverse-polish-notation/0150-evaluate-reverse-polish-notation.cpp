class Solution {
public:
    int evalRPN(vector<string>& s) {
        int n = s.size();
        stack<long long int>st;
        
        for(int i = 0 ; i < n ; i++){
            
            string curr = s[i];
            
            if(curr=="+"||curr=="-"||curr=="*"||curr=="/"){
                long long int a = st.top();
                st.pop();
                long long int b = st.top();
                st.pop();
                if(curr=="+"){
                    st.push(a+b);
                }
                if(curr=="-"){
                    st.push(b-a);
                }
                if(curr=="*"){
                    st.push(a*b);
                }
                if(curr=="/"){
                    st.push(b/a);
                }
            }
            else{
                st.push(stoi(curr));
            }
        }
        return st.top();
        
    }
};