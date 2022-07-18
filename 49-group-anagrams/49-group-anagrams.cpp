class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string , vector<string>> mp;
        vector<vector<string>> ans;
        
        for(int i = 0 ; i < strs.size() ; i++ ){
            string curr = strs[i];
            sort(curr.begin() , curr.end());
            string sort_curr = curr;
            
            mp[sort_curr].push_back(strs[i]);
        }
        
        for(auto x : mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};