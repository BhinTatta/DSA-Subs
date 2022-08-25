class Solution {
public:
    bool canConstruct(string ransom, string magazine) {
        unordered_map<char,int> mp;
        for(char x : magazine) mp[x]++;
        for(char x : ransom ){
            if(mp[x]<=0) return false;
            mp[x]--;
        }
        return true;
    }
};