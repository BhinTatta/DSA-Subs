class Solution {
public:
    bool checkInclusion(string s, string p) {
        int n = s.size() , m = p.size();
        vector<int> smap(26,0);
        vector<int> pmap(26,0);
        
        //fill smap
        for(char c : s){
            int pos = c - 'a';
            smap[pos]++;
        }
        bool flag = false;
        int l = 0 , r = 0;
        while(r<m){
            int curr = p[r]-'a';
            if(smap[curr]==0){
                l=r+1;
                r++;
                for(int i = 0 ; i < 26 ; i++) pmap[i]=0;
                continue;
            }
            else{
                pmap[curr]++;
                if(r-l+1 == n){
                    //cout<< p.substr(l,r-l+1)<<endl;
                    if(smap==pmap) return true;
                    else{
                        int lpos = p[l]-'a';
                        pmap[lpos]--;
                        l++;
                    }
                }
            }
            r++;
        }
        return false;
    }
};