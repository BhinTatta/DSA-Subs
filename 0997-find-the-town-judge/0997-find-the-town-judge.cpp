class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n+1,0) , out(n+1,0);
        for(auto it : trust){
            int a = it[0] , b = it[1];
            in[b]++;
            out[a]++;
        }
        
        for(int i = 1 ; i <= n ; i++){
            if(in[i]==n-1 && out[i]==0) return i;
        }
        
        return -1;
    }
};