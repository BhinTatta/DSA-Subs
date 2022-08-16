class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(char x : s) mp[x]++;
        for(int i = 0 ; i < s.length() ; i++){
            char curr = s[i];
            if(mp[curr]==1) return i;
        }
        return -1;
    }
};