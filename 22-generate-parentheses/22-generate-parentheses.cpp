class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> store;
        string temp = "(";
        maker(store,temp,n-1,n);
        return store;
    }
    
    void maker(vector<string> &store , string temp , int open , int close){
        if(close<open) return; // if closing brackets are less than opening, return;
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
    
};