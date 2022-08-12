class Solution {
public:
    bool isHappy(int n) {
        long long x = n;
        unordered_map<long long, long> mp;
        
        return helper(x , mp);

    }
    
    bool helper(long long n , unordered_map<long long , long> &mp){
        
        if(n == 1) return true;
        
        
        
        long long newnum = 0;
        while(n > 0){
            newnum +=  (n%10 )*(n%10 );
            n /= 10;
        }
        //cout<<newnum<<endl;
        if( mp[newnum] >= 1 ) return false;
        mp[newnum]++;
        
        return helper(newnum , mp);
    }
};