class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        if(nums[0]>0) return ans;
        
        int i = 0;
        while(i < n-2){
            int curr = nums[i];
            if(curr>0){
                i++;
                break;
            }           
            int low = i+1, high = n-1;
            int req = -curr;
            while(low<high){  
                //cout<<curr<<" "<<nums[low]<< " "<<nums[high]<<endl;
                int sum = nums[low] + nums[high];
                if(sum == req){
                    ans.push_back({curr,nums[low],nums[high]});
                    high--;
                    while(high>low && nums[high]==nums[high+1]) high--;
                    low++;
                    while(low<high && nums[low]==nums[low-1]) low++;
                }
                else if(sum<req){
                    low++;
                    while(low<high && nums[low]==nums[low-1]) low++;
                }
                else{
                    high--;
                    while(high>low && nums[high]==nums[high+1]) high--;
                }
            }
            i++;
            while(i<n-2 && nums[i]==curr) i++;
        }
        return ans;
    }
};