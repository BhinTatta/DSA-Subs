class Solution {
public:
    long long makeIntegerBeautiful(long long n, int k) {
        long long int ans = 0;
        int sum = dig(n);
        if(sum<k) return 0;
        
        while(dig(n)>k){
            long long int temp = n;
            int i = 0;
            while( (temp%10) ==0){
                i++;
                temp /= 10;
            }
            long long int req = (10- (temp%10)) * pow(10,i);
            ans += req;
            n += req;
            //cout<<n<<" + "<<req<<" -> "<<temp<< endl;
        }
        
        return ans;
    }
    
    int dig(long long int n){
        int ans = 0;
        while(n){
            ans += n%10;
            n/=10;
        }
        return ans;
    }
};