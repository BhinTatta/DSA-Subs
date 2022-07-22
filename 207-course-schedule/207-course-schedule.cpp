class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        
        vector<vector<int>> adj(n);
        
        for(auto pair : prereq){
            adj[pair[0]].push_back( pair[1] );
        }
        
        vector<int> vis(n , 0);
        
        for(int i=0 ; i<n ; i++){
            if(vis[i] == 0){
                if( dfs( adj , vis , i ) )
                    return false;
            }
        }
        
        return true;
    }
    
    bool dfs(  vector<vector<int>> &adj , vector<int> &vis , int course ){
        if(vis[course]==2) return true;
        if(vis[course] == 1) return false;
        vis[course] = 2;
        
        for( auto pre : adj[course]){
            if( dfs(adj , vis , pre) )
                return true;
        }
        
        vis[course] = 1;
        return false;
    }
};







