class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        int n = ast.size();
        
        for(int i = 0 ; i < n ; i++){
            int curr = ast[i];
            
            if(st.empty()) st.push(curr);
            
            else if( st.top() * curr > 0 ) st.push(curr);
            
            else if( st.top()>0 && curr<0 ){
                while(!st.empty() && (st.top()>0 && st.top() < curr*-1)){
                    st.pop();
                }
                if(st.empty()) st.push(curr);
                else if(st.top() == -1*curr) st.pop();
                else if(st.top()<0) st.push(curr);
            }
            
            else st.push(curr);
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};