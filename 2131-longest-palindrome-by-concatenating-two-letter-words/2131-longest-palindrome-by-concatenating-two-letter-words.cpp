class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        unordered_map<string,int> mp;
        
        for(auto s : words){
            string r = rev(s);
            if(mp.find(r)==mp.end()){
                mp[s]++;
            }
            else if(mp[r] > 0){
                ans += 4;
                mp[r]--;
            }
            else{
                mp[s]++;
            }
        }
        for(auto it : mp){
            string a = it.first , b = rev(a);
            if(a==b && it.second > 0){
                ans+=2;
                break;
            }
        }
        return ans;
    }
    
    string rev(string s){
        reverse(s.begin() , s.end());
        return s;
    }
};