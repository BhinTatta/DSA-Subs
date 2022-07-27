class Solution {
public:
    vector<int>ans;

    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < prereq.size() ; i ++){
            adj[prereq[i][0]].push_back(prereq[i][1]);
        }
        vector<int> vis(n,0);
        for(int i = 0 ; i < n ; i++ ){
            if(vis[i]==0) dfs(adj , vis , i);
        }

        vector<int> temp;
        return ans.size()==n ? ans : temp;
    }
    
    void dfs(vector<vector<int>> &adj , vector<int> &vis , int i){
        if(vis[i]==2) return;
        vis[i] = 1;   
        for(auto it : adj[i]){
            if(vis[it]==1) return;
            if(vis[it]==0) dfs(adj , vis , it);
        }  
        vis[i]=2;
        ans.push_back(i);
    }
};