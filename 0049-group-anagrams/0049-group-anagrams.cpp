class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> mp;
        
        for(auto str : strs){
            string freq = helper(str);
            mp[freq].push_back(str);
        }
        
        vector<vector<string>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
    
    string helper(string &s){
        int nums[26];
        memset(nums,0,sizeof(nums));
        for(char i : s){
            nums[i-'a']+=1;
            //cout<<nums[i-'a']<<" ";
        }
        // cout<<endl;
        string ans = "";
        
        for(int i = 0 ; i < 26 ; i++){
            ans += to_string(nums[i]);
            ans+=",";
        }
        //ans += s;
        //cout<<s<<" = "<<ans<<endl;
        return ans;
    }
};