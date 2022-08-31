class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        vector<int> lund(n);
        
        for(int i = 0 ; i < k ; i++){
            lund[i] = nums[n-k+i];
            
        }
        for(int i = k ; i < n ; i++){
            lund[i] = nums[i-k];
        }
        nums = lund;
    }
};