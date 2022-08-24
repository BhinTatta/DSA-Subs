class Solution {
public:
    bool isPowerOfThree(int n) {
        int maxi = INT_MAX;
        long long curr = 1;
        while(curr <= n && curr<maxi){
            if(curr == n) return true;
            curr *= 3;
        }
        return 0;
    }
};