class Solution {
public:
    int firstUniqChar(string s) {
        int mp[26];
        memset(mp , 0 ,sizeof(mp));
        for(char x : s){
            int pos = x-'a';
            mp[pos]++;
        }
        for(int i = 0 ; i < s.length() ; i++){
            int curr = s[i]-'a';
            if(mp[curr]==1) return i;
        }
        return -1;
    }
};