class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answ(n);
        for(int i = 1 ; i <= n ; i ++){
            string ans = "";
            if(i%3==0) ans+="Fizz";
            if(i%5==0) ans+="Buzz";          
            answ[i-1] = ans=="" ? to_string(i) : ans; 
        }
        return answ;
    }
};