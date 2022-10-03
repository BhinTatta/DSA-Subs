class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < graph.size() ; i++){
            for(auto it : graph[i]){
                adj[it].push_back(i);
            }
        }
        
        vector<int> ans = topo(adj);
        
        sort(ans.begin() , ans.end());
        return ans;
        
    }
    
    vector<int> topo(vector<vector<int>>& adj){
        int n = adj.size();
        
        vector<int> ind(n,0);
        for(auto node : adj){
            for(auto it : node) ind[it]++;
        }
        queue<int> q;
        for(int i = 0 ; i < n ; i++){
            if(ind[i]==0) q.push(i);
        }
        
        vector<int>ans;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            //cout<<curr<<" ";
            ans.push_back(curr);
            for(int node : adj[curr]){
                ind[node]--;
                if(ind[node]==0) q.push(node);
            }
        }
        
        return ans;
    }
};










