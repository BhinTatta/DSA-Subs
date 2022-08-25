class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int l = 1 , r = x/2;
        int ans;
        //cout<<INT_MAX;
        while(l<=r){
            long long int mid = (l+r)/2;
            long long int sqr = mid*mid;
            if(sqr == x) return mid;
            else if(sqr < x){
                l = mid+1;
                ans = mid;
            }
            else r = mid-1;
        }
        return ans;
    }
};