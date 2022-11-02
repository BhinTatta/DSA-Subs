class Solution {
public:
    int nextGreaterElement(int m) {
        vector<int> nums = rev(m);
        int n = nums.size();
        if(n==1) return -1;
        
        int a = 0, b = 0;
        
        for(int i = n-2 ; i >= 0 ; i--){
            if(nums[i]<nums[i+1]){
                a = i;
                break;
            }
        }
        
        for(int i = n-1 ; i >= 0 ; i--){
            if(nums[i]>nums[a]){
                b = i;
                break;
            }
        }
        
        if(a!=b) swap(nums[a] , nums[b]);
        if(a==0 && b==0) reverse(nums.begin() , nums.end());
        else reverse(nums.begin()+a+1 , nums.end());
        
        long long int ans = helper(nums);
        
        //cout<<ans<<endl;
        if(ans>INT_MAX || ans<=m) return -1;
        return ans;
    }
    
    long long int helper(vector<int>&nums){
        long long int ans = 0;
        reverse(nums.begin() , nums.end());
        for(int i = 0 ; i < nums.size() ; i++){
            ans += nums[i] * pow(10,i);
        }
        return ans;
    }
    vector<int> rev(int n){
        vector<int> nums;
        while(n){
            nums.push_back( n % 10);
            n /= 10;
        }
        reverse(nums.begin() , nums.end());
        return nums;
    }
};