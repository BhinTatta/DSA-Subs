class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        for(auto it : edges){
            vector<bool> vis(n+1 , false);
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            if(dfs(adj , vis , it[0] , -1)) return it;
        }
        return {};
    }
    
    bool dfs(vector<vector<int>>& adj , vector<bool> &vis , int curr , int par){
        if(vis[curr]) return true;
        vis[curr] = true;
        for(auto it : adj[curr]){
            if(it!=par){
                if(dfs(adj , vis, it , curr)) return true;
            }
        }
        return false;
    }
};