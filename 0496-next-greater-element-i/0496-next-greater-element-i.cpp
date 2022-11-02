class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        unordered_map<int,int> mp;
        
        for(int i = n-1 ; i >= 0 ; i--){
            int curr = nums[i];
            while(!st.empty() && st.top()<= curr) st.pop();
            int x = st.empty()==true ? -1 : st.top();
            mp[curr] = x;
            st.push(curr);
        }
        
        vector<int> ans;
        for(int i : nums1){
            ans.push_back( mp[i] );
        }
        
        return ans;
    }
};