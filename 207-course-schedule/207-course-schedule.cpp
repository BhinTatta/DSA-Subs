class Solution {
public:
    
    
    bool checker( vector<vector<int>> &adj, vector<int> &vis, int course ){
        if( vis[course]==1 ) return true;
        
        
        if(vis[course]==0){
            vis[course]=1;
            for(auto edge : adj[course]){
                if(checker( adj , vis , edge )) 
                    return true;
            }
        }
        
        vis[course] = 2;
        return false;
        
    }
    
    bool canFinish(int num, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(num);
        for(int i = 0 ; i < prereq.size() ; i++){
            adj[prereq[i][0]].push_back(prereq[i][1]);
        }
        
        vector<int> vis(num , 0 );
        
        for(int i = 0 ; i < num ; i++){
            
            if(checker( adj , vis , i )) return false;
            
        }
        
        return true;
    }

};