class Solution {
public:
    bool isUgly(int n) {
        if(n==0) return false;
        if(n==1) return true;
        int x = n;
        if(n%5==0) n/=5;
        if(n%3==0) n/=3;
        if(n%2==0) n/=2;
        if(x==n) return false;
        return isUgly(n);
    }
};