class Solution {
public:
    int ans = INT_MAX;
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : roads){
            int a = it[0] , b = it[1] , c = it[2];
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        vector<int> vis(n+1 , 0);
        helper(1 , adj , vis);
        return ans;
        
    }
    
    void helper(int curr , vector<vector<pair<int,int>>> &adj , vector<int> &vis){
        if(vis[curr]) return;
        vis[curr] = 1;
        
        for(auto it : adj[curr]){
            int node = it.first , dis = it.second;
            ans = min(dis,ans);
            if(!vis[node]) helper(node , adj , vis);
        }
        
        }
};