class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int i = 0 , ans = 0;
        int flip = 0;
        while(i<n){
            char curr = s[i];
            if(curr == '0' && (flip & 1)){
                flip++;
            }
            else if(curr == '1' && (flip & 1)==0){
                flip++;
            }
            i++;
        }
        return flip;
    }
};