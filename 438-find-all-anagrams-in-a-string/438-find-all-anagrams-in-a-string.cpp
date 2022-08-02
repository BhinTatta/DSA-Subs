class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = p.length() , n = s.length();
        vector<int> pmap(26,0) , smap(26,0);
        
        for(char it : p ){
            pmap[it - 'a']++;
        }
        vector<int> ans;
        int l = 0 , r = 0;
        
        while(r < n){
            int curr = s[r]-'a';
            if(pmap[curr]==0){
                for(int i = 0 ; i < 26 ; i++) smap[i]=0;
                l = r+1;
            }
            else{
                smap[curr]++;
                if(r-l+1 == m && check(smap , pmap)){
                    ans.push_back(l);
                    smap[s[l]-'a']--;
                    l++;
                }
                else{
                    while(r-l+2 > m){
                        smap[s[l]-'a']--;
                        l++;
                    }
                }
            }
            r++;
        }
        return ans;
    }
    
    bool check(vector<int> &s , vector<int>&p){
        return s==p;
    }
};