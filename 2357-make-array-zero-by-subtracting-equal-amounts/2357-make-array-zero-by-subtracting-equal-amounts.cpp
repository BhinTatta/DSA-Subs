class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(int x : nums){
            if(x!=0 && mp.find(x)==mp.end()){
                mp[x]++;
                ans++;
            }
        }
        return ans;
    }
};