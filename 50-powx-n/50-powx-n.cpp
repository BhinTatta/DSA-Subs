class Solution {
public:
    unordered_map<long long int,double> mp;
    
    double myPow(double x, int m) {
        long long int n = m;
        double ans;
        if(n==0 || x == 1) return 1; 
        if(n>0) ans = helper(abs(x),n);
        if(n<0) ans = helper(abs(x) , -n);
        
        if(n<0){
            ans = 1/ans;
        }
        if(x<0 && n>0){
            n%2==0 ? ans = ans : ans = -ans;
        }
        return ans;
    }
    
    double helper(double x , long long int n){
        if(n==0) return 1;
        if(mp.find(n)!=mp.end()) return mp[n];
        
        if(n&1) return mp[n] = helper(x , n/2) * helper(x , n/2) * x;
        return mp[n] = helper(x , n/2) * helper(x , n/2);
    }
};