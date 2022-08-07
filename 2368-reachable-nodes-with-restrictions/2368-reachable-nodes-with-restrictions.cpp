class Solution {
public:
    int ans = 1;
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        unordered_map<int,int> rest;
        vector<int> vis(n,0);
        for(int i = 0 ; i < n-1 ; i++){
            int a = edges[i][0] , b = edges[i][1];
            adj[min(a,b)].push_back(max(a,b));
            adj[max(a,b)].push_back(min(a,b));
        }
        for(int i : restricted) rest[i]++;
        queue<int> q;
        q.push(0);
        vis[0]=1;
        dfs(adj , q , rest,vis);
        return ans;
        
    }
    
    void dfs( vector<vector<int>>&adj , queue<int> q , unordered_map<int,int> &rest, vector<int> &vis ){
        
        queue<int> newq;
        while(!q.empty()){
            int curr = q.front();
            //cout<<curr<<endl;
            q.pop();
            for(int it : adj[curr]){
                if(rest.find(it)==rest.end() && vis[it]==0){
                    newq.push(it);
                    ans++;
                    vis[it]=1;
                }
            }
        }
        if(!newq.empty()) dfs(adj , newq , rest, vis);
    }
};