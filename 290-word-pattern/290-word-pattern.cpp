class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        int i = 0;
        int n = s.length();
        int count = 0;
        while(i<n){
            int l = i;
            while(l<n && s[l]!=' ') l++;
            string curr = s.substr(i , l-i);
            words.push_back(curr);
            i = l+1;
            //cout<<curr<<endl;
            count++;
        }
        unordered_map<char,string> mp;
        unordered_map < string , char> mp2;
        i = 0;
        int m  = pattern.length();
        if(m!=count) return 0;
        while(i<m){
            char curr = pattern[i];
            if(mp.find(curr) ==mp.end() && mp2.find(words[i])==mp2.end()){
                mp[curr] = words[i];
                mp2[words[i]] = curr;
            }
            else{
                if(mp[curr]!=words[i] || mp2[words[i]]!=curr) return false;
            }
            i++;
        }
        
        return 1;
    }
};