class Solution {
public:
    bool halvesAreAlike(string s) {
        vector<char> vec = {'a','e','i','o','u','A','E','I','O','U'};
        unordered_map<char,int> mp;
        for(auto i : vec) mp[i]++;
        int a =0  , b = 0;
        for(int i = 0 ; i < s.size()/2 ; i++) if(mp.find(s[i])!=mp.end()) a++;
        for(int i = s.size()/2 ; i < s.size() ; i++) if(mp.find(s[i])!=mp.end()) b++;
        return a==b;
    }
};