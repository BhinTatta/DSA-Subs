class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto i : s) mp[i]++;
        vector<pair<int,char>> vec;
        for(auto i : mp){
            vec.push_back({i.second , i.first});
        }
        sort(begin(vec) , end(vec));
        string ans;
        for(auto i : vec){
            int x = i.first;
            while(x-->0){
                ans.push_back(i.second);
            }
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};