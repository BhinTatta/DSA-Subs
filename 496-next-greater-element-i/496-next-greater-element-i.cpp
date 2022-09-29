class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        unordered_map<int,int> mp;
        
        for(int i = n-1 ; i >= 0 ; i--){
            int curr = nums[i];
            while(!st.empty() && st.top()<=curr) st.pop();
            if(st.empty()) mp[curr] = -1;
            else mp[curr] = st.top();
            st.push(curr);
        }
        
        vector<int>ans;
        for(auto it : nums1){
            ans.push_back(mp[it]);
        }
        
        return ans;
    }
};