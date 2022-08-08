class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        
        for(int i = 0 ; i < n-2 ; i++){
            int curr = nums[i];
            int diff = nums[i+1]-nums[i];
            int j = i+1;
            int currlen = 1;
            while(j<n && nums[j]-nums[j-1]==diff){
                currlen++;
                //cout<<nums[j-1]<<" "<<nums[j]<<" = "<<currlen<<endl;
                if(currlen>=3) ans++;
                j++;
            }
        }
        return ans;
    }
};