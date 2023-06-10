class Solution {
public:
    char nextGreatestLetter(vector<char>& nums, char k) {
        int n = nums.size();
        int l = 0 , r = n-1;
        
        while(l<=r){
            int req = k-'a';
            int m = (r+l)/2;
            int mid = nums[m]-'a';

            if(mid <= req){
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        
        return l<n ? nums[l] : nums[0];
        
    }
};