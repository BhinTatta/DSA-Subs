class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int size = pow(2,n);
        for(int i = 0 ; i < size ; i++){
            vector<int> temp;
            for(int j = 0 ; j < n ; j++){
                if(i>>j & 1) temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }        
        return ans;
    }
};