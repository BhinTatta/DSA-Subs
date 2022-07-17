class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==1 || n==0) return n;
        unordered_map<char , int> mp;
        int maxi = 0;
        
        int r = 0 , l = 0;
        
        while(r <= n){
            maxi = max(maxi , r-l+1);
            char curr = s[r];
            if(mp.find(curr)!=mp.end() && mp[curr]>=l){
                l = mp[curr]+1;
                mp[curr] = r;
            }
            else{
                mp[curr]=r;
            }
            //cout<<s[l] <<" - "<<s[r]<< " "<<"(" << l <<"-"<<r<<")"<<endl;
            r++;
        }
        return maxi-1;
    }
};