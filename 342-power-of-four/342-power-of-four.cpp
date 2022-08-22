class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n<=0) return 0;
        long long lim = INT_MAX;
        long long curr = 1;
        while(curr <= n || curr < lim){
            if(curr == n ) return true;
            curr = 4*curr;
        }
        return false;
    }
};