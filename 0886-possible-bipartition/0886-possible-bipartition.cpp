class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto it : dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n+1 , 0);
        vector<int> color(n+1 , 0);
        queue<int> q;
        
        for(int i = 0 ; i <= n ; i++){
            if(vis[i]) continue;
            color[i] = 1;
            q.push(i);
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                if(vis[curr]) continue;
                vis[curr] = 1;
                for(auto it : adj[curr]){
                    if(color[it]==color[curr]) return 0;
                    
                    color[it] = -color[curr];
                    q.push(it);
                }
                
            }
        }
        
        
        return true;
    }
    
    
};