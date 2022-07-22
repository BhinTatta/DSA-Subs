class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color( n , 0);
        
        for(int i=0 ; i<n ; i++){
            if(color[i] != 0) continue;
            
            if(dfs( i , color , graph , 1 ) ) return false;
        }
        
        return true;
    }
    
    bool dfs( int i , vector<int> &color , vector<vector<int>>& graph , int col ){
        if( color[i] == col*-1 ) return true;
        if(color[i]!=0) return false;
        
        color[i] = col;
        
        for(auto adj : graph[i]){
            if(dfs( adj , color , graph , -1*col )) return true;
        }
        
        return false;
        
    }
};