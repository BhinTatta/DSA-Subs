class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size();
        vector<pair<string,int>> store;
        
        for(int i = 0 ; i < n ; i++){
            string word = words[i];
            
            store.push_back( { makepattern(word) , i });
        }
        
        string req_pattern = makepattern(pattern);
        
        vector<string> ans;
        
        for(auto it : store){
            string currpattern = it.first;
            int pos = it.second;
            
            if(currpattern == req_pattern){
                ans.push_back(words[pos]);
            }
        }
        
        return ans;
    }
    
    string makepattern(string s){
        int n = s.length();
        unordered_map<char , int> mp;
        
        int pos = 1;
        
        string pattern = "";
        
        for(int i = 0 ; i < n ; i++){
            char curr = s[i];
            if(mp.find(curr) == mp.end() ){
                mp[curr]=pos;
                pos++;
            } 
            pattern.push_back(mp[curr]);
        }
        
        return pattern;
    }
    
};