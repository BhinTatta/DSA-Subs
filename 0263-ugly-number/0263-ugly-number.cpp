class Solution {
public:
    bool isUgly(int n) {
        if(n==0) return 0;
        vector<int> nums = {2,3,5};
        for(int i : nums){
            while(n%i==0) n/=i;
        }
        return n==1;
    }
};