class Solution {
public:
    int convert(int n){
        long long int ans = 0;
        while(n){
            int dig = n%10;
            n /= 10;
            ans += pow(dig,2);
        }
        return ans;
    }
    
    
    bool isHappy(int n) {
        long long int a = n, b = n;
        bool flag = true;
        
        while(a!=1 && b!=1 && (flag || a!=b)){
            if(a==n && b==n) flag = false;
            a = convert(a);
            b = convert(b);
            b = convert(b);
        }
        
        if(a==1 || b==1) return true;
        return 0;
        
    }
};