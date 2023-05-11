class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> count(52 , 0);
        vector<int> ans;
        
        for(int i = 0 ; i < k-1 ; i++){
            int curr = nums[i];
            if(curr<0) count[ abs(curr) ]++;
        }
        
        for(int i = k-1 ; i < n ; i++ ){
            
            int add = i , rem = i-k < 0 ? -1 : i-k;
            
            int curr = nums[i];
            if(curr<0) count[ abs(curr) ]++;
            if(rem!=-1 && nums[rem]<0) count[ abs(nums[rem]) ]--;
            
            int temp = helper(count , x);
            
            ans.push_back(-temp);
        }
        
        return ans;
    }
    
    int helper(vector<int> &count , int k){
        int n = count.size() , i = n-1;
        
        while(i>=0 && k>0){
            // cout<<i<<" -- "<<count[i]<<endl;
            k -= count[i];
            i--;
        }
        // cout<<k<<" "<<i<<endl;
        return k<=0 ? i+1 : 0;
    }
    

    
};