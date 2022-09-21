class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        long long int sum = 0;
        for(int i : nums) if(!(i&1)) sum += i;
        vector<int> ans;
        for(int i = 0 ; i < q.size() ; i++){
            int val = q[i][0];
            int idx = q[i][1];
            int num = nums[idx];
            
            if(num&1){
                nums[idx]+=val;
                if(  !(nums[idx]&1) ){
                    sum+=nums[idx];
                }
            }
            else{
                sum -= nums[idx];
                nums[idx] += val;
                if(  !(nums[idx]&1) ){
                    sum+=nums[idx];
                }
            }
            ans.push_back(sum);
        }
        
        return ans;
    }
};