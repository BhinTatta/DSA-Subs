class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& nums) {
        long long int ans = 0;
        int n = nums.size();
        unordered_map<double,int> mp;
        for(int i = n-1 ; i >= 0 ; i--){
            double a = nums[i][0] , b = nums[i][1];
            if(mp.find(a/b)!=mp.end()){
                ans+= mp[a/b];
            }
            mp[a/b]++;
        }
        return ans;
    }
};