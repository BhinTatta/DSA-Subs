class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int l = nums.size();
        int ans = 0 , i = 0;
        
        if(l==1){
            //cout<<nums[i]<<" "<<n<<endl;
            if(nums[i]==0 && n<=1) return true;
            if(nums[i]==1 && n==0) return true;
            return false;
        }
        while(i<l){
            if(nums[i]) i+=2;
            
            else if(i==0 && nums[i]==0 && nums[i+1]==0){
                ans++;
                i+=2;
            }
            
            else if(i==l-1 && nums[i]==0 && nums[i-1]==0){
                ans++;
                i+=2;
            } 
            
            else if(nums[i]==0 && nums[i+1]==0 && nums[i-1]==0){
                ans++;
                i+=2;
            }
            
            else i++;
        }

        return ans >= n;
    }
};