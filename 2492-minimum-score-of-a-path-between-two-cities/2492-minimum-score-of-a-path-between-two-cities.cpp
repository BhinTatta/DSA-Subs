class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : roads){
            int a = it[0] , b = it[1] , c = it[2];
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        
        vector<int> vis(n+1 , 0);
        
        int ans = INT_MAX;
        
        queue<int> q;
        q.push(1);
            
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
           
            
            for(auto it : adj[curr]){
                
                int node = it.first , len = it.second;
                ans = min(ans , len);
                
                if(!vis[node]){
                    vis[node]=1;
                    q.push(node);
                }
            }
            
        }
        
        return ans;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};