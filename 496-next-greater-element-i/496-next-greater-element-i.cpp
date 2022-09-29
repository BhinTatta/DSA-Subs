class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums) {
        int n = nums.size();
        unordered_map<int ,int> mp;
        mp[nums[n-1]] = -1;
        int i = n-2;
        
        while(i>=0){
            int curr = nums[i];
            int j = i+1;
            while(j<n){
                if(nums[j]>curr){
                    mp[curr]=nums[j];
                    break;
                }
                else if(nums[j]<curr){
                    if(mp[nums[j]]==-1){
                        mp[curr] = -1;
                        break;
                    }
                }
                j++;
            }
            if(j==n) mp[curr]=-1;
            //cout<<mp[curr]<<" ";
            i--;
        }
        
        vector<int>ans;
        for(int it : nums1){
            ans.push_back( mp[it] );
        }
        
        return ans;
    }
};