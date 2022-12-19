class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            int a = it[0] , b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> vis(n,0);
        dfs(adj,vis,source);
        return vis[destination]==1;
    }
    
    void dfs(vector<vector<int>> &adj , vector<int>& vis , int s){
        if(vis[s]==1) return;
        vis[s]=1;
        for(auto it : adj[s]){
            dfs(adj , vis , it);
        }
    }
};