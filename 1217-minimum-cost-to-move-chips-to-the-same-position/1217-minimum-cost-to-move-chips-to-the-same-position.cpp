class Solution {
public:
    int minCostToMoveChips(vector<int>& nums) {
        int n = nums.size();
        //vector<long long int> arr(n);
        long long int a = 0 , b = 0;
        for(int i = 0 ; i < n ; i++){
            int curr = nums[i];
            a += (curr)%2;
            b += (curr+1)%2;
        }
        return min(a,b);
    }
};