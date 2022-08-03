class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> store;
        string temp = "(";
        maker(store,temp,n-1,n);
        
        vector<string> ans;
        validate(store,ans);
        return ans;
    }
    
    void maker(vector<string> &store , string temp , int open , int close){
        if(open==0 && close == 0){
            store.push_back(temp);
            return;
        }
        
        if(open > 0){
            temp.push_back('(');
            maker(store,temp,open-1,close);
            temp.pop_back();
        }
        if(close>0){
            temp.push_back(')');
            maker(store,temp,open,close-1);
            temp.pop_back();
        }
        
    }
    
    void validate(vector<string> &store , vector<string> &ans){        
        for(string s : store){
            bool isvalid = true;
            stack<char> st;
            
            for(char par : s){
                // check for closing par
                if( par == ')' ){
                    if(st.empty()){
                        isvalid = false;
                        break;
                    }
                    else st.pop();
                }
                else st.push(par);
            }
            
            if(isvalid && st.empty()) ans.push_back(s);
        }
    }
};