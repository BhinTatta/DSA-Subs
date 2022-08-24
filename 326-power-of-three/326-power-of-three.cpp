class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1) return 0;
        string base = "";
        while(n){
            string dig = to_string(n%3);
            base+=dig;
            n/=3;
        }      
        for(int i = 0 ; i < base.length()-1 ;i++){
            if(base[i]!='0') return 0;
        }
        
        return base[base.length()-1]=='1';
    }
};