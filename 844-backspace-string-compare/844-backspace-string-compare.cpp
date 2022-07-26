class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>stack1;
        stack<char>stack2;
        createstack(s , stack1);
        createstack(t , stack2);
        
        if(stack1.size()!=stack2.size()) return false;
        while(!stack1.empty()){
            if(stack1.top()!=stack2.top()) return false;
            stack1.pop();
            stack2.pop();
        }
        
        return true;
    }
    
    void createstack(string s , stack<char>&st){
        int n = s.length();
        for(char curr : s){
            if(curr == '#' && !st.empty()){
                st.pop();
            }
            else if(curr != '#'){
                st.push(curr);
            }
        }
    }
};