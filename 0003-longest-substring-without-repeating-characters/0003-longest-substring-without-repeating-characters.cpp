class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0 , n = s.size() , l = 0 , r = 0;
        unordered_map<char,int> mp;
        while(r<n){
            char curr = s[r];
            if(mp.find(curr)==mp.end()){
                mp[curr] = r;
            }
            else{
                while(mp.find(s[r]) != mp.end() ){
                    mp.erase(s[l]);
                    l++;
                }
                mp[curr] = r;
            }
            //cout<<s.substr(l , r-l+1)<<endl;
            ans = max(r-l+1 , ans);
            r++;
        }
        return ans;
    }
};