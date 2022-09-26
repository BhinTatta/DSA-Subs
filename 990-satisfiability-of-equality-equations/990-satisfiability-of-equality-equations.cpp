class Solution {
public:
    int uf[26];
    
    int find(int x){
        return uf[x] == x ? x : (uf[x] = find(uf[x]));
    }
    
    bool equationsPossible(vector<string>& eq) {
        for(int i = 0 ; i < 26 ; i++) uf[i] = i;
        
        for(auto s : eq){
            if(s[1]=='=') uf[find( s[0] - 'a' )] = find( s[3] - 'a' );
        }
        
        for(auto s : eq){
            if(s[1]=='!'){
                if( find(s[0]-'a') == find(s[3] - 'a') ) return false;
            }
        }
        
        return true;
    }
};