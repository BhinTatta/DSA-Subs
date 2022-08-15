class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        int maxi = 0;
        int ans = 0;
        for(int i = s.length()-1 ; i >= 0 ; i--){
            int curr = mp[s[i]];
            if(curr<maxi) ans -= curr;
            else ans += curr;
            maxi = max(maxi,curr);
        }
        return ans;
    }
};