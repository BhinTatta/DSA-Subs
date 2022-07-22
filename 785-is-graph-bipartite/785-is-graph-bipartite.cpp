class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color( n , 0);
        queue<int> q;
        
        for(int i=0 ; i<n ; i++){
            if(color[i]!=0) continue;
            color[i] = 1;
            q.push(i);
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                
                for(auto adj : graph[node]){
                    if( color[adj] == 0 ){
                        color[adj] = -1 * color[node];
                        q.push(adj);
                    }
                    else if( color[adj] == color[node] ){
                        return false;
                    }
                }
            }
            
        }
        
        return true;
    }
};