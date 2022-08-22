class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int>temp = {0};        
        dfs(graph ,ans , temp, n , 0);
        return ans;
    }
    
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans , vector<int> temp , int n, int node){
        if(node == n-1){
            ans.push_back(temp);
            return;
        }        
        for(auto it : graph[node]){
            temp.push_back(it);
            dfs(graph , ans, temp, n , it);
            temp.pop_back();
        }
    }
};