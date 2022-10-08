class Solution {
public:
    char digtochar(int x){
        if(x<10) return (char) ('0'+x);
        else return (char) ('a' + (x-10));
    }
    string toHex(int n) {
        if(n==0) return "0";
        unsigned int num = n;
        //cout<<num;
        string res;
        while(num){
            res.push_back(digtochar(num%16));
            num/=16;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};