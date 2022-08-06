class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int>st;
        st.push(-1);
        vector<int> ans(n);
        
        for(int i = n-1 ; i >= 0 ; i--){
            int curr = temp[i];
            
            while(st.top()!=-1 && temp[st.top()]<=curr){
                st.pop();
            }
            
            if(st.top()==-1) ans[i]=0;      
            else{
                ans[i] = st.top()-i;
            }
            
            st.push(i);
        }
 
        return ans;
    }
};