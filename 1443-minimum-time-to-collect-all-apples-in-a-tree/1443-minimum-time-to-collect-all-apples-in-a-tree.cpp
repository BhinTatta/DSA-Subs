class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& has) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            int a = it[0] , b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> vis(n,0);
        int ans = helper(adj , has , vis , 0);
        
        return ans==0 ? 0 : ans-2;
    }
    
    int helper(vector<vector<int>>& adj , vector<bool>& has , vector<int> &vis , int node){
        //cout<<node<<endl;
        if(vis[node]) return 0;
        vis[node] = 1;
        
        int ans = 0;
        
        for(auto it : adj[node]){
            if(!vis[it]) ans += helper(adj , has , vis , it);
        }
        
        if(ans == 0 && has[node]){
            //cout<<node<<" = "<<"2"<<endl;
            return 2;
        }
        if(ans != 0 ){
            //cout<<node<<" = "<<ans+2<<endl;
            return ans+2;
        }
        //cout<<node<<" = "<<"0"<<endl;
        return 0;
    }
};