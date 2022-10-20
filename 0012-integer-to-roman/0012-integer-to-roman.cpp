class Solution {
public:
    string intToRoman(int num) {
        vector<int> dig = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> str = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int n = dig.size();
        string ans = "";
        while(num){
            for(int i = 0 ; i < n ; i++){
                if(dig[i]<=num){
                    int cnt = num / dig[i];
                    num = num % dig[i];
                    for(int j = 0 ; j < cnt ; j++) ans+=str[i];
                    break;
                }
            }
        }
        return ans;
    }
};