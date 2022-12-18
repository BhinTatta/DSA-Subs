class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<pair<int,int>> st;
        vector<int> ans(n);
        
        for(int i = n-1 ; i >= 0 ; i--){
            int curr = temp[i];
            while(!st.empty() && st.top().first <= curr) st.pop();            
            ans[i] = st.empty() == true ? 0 : st.top().second - i;            
            st.push({curr,i});            
        }
        
        return ans;
    }
};