class Solution {
public:
    unordered_map<string, bool> mp;
    bool isScramble(string s1, string s2) {
        vector<int> cnt(26, 0);
        for(int i=0; i<s1.size(); i++){
            cnt[s1[i]-'a']++;
            cnt[s2[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(cnt[i]!=0) return false;
        }
        if(s1.length() != s2.length()) return false;
        return solve(s1,s2);
    }
    
    bool solve(string s1 , string s2){
        //cout<<s1<<" "<<s2<<endl;
        string keystr = s1 + s2;
        if(mp.find(keystr)!=mp.end()) return mp[keystr];
        vector<int> cnt(26, 0);
        for(int i=0; i<s1.size(); i++){
            cnt[s1[i]-'a']++;
            cnt[s2[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(cnt[i]!=0) return mp[keystr] = false;
        }
        int n = s1.length();
        if(n<=1) return mp[keystr] = (s1==s2);
        if(s1==s2) return mp[keystr] = true;
        
        bool flag = false;
        for(int i = 1 ; i < n ; i++){
            bool swap1 = solve(s1.substr(0,i) , s2.substr(n-i,i));
            bool swap2 = solve(s1.substr(i,n-i) , s2.substr(0,n-i));
            bool noswap1 = solve(s1.substr(0,i) , s2.substr(0,i));
            bool noswap2 = solve(s1.substr(i,n-i) , s2.substr(i,n-i));
            
            flag = (  (swap1 && swap2) || (noswap1 && noswap2));
            if(flag) break;
        }
        
        return mp[keystr] = flag;
    }
    
    // bool prune(string a , string b){
    //     int acount[26];
    //     int bcount[26];
    //     for(int i = 0 ; i < a.length() ; i++){
    //         acount[a[i]-'a']++;
    //         bcount[b[i]-'a']++;
    //     }
    //     return acount==bcount;
    // }
};