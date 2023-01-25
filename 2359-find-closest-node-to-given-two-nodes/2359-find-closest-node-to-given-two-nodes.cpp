class Solution {
private:
    int n;
    
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> vis1(n,-1) , vis2(n,-1);
        
        dfs(edges , node1, 0 , vis1);
        dfs(edges , node2 , 0 , vis2);
        
        int ans = INT_MAX , idx = -1;
        for(int i = 0 ; i < n ; i++){
            if(vis1[i]==-1 ||vis2[i]==-1) continue;
            int mini = max(vis1[i] , vis2[i]);
            if( mini!=-1 && mini < ans){
                ans = mini;
                idx = i;
            }
        }
        return idx;
    }
    
    void dfs(vector<int> &edges , int node , int d , vector<int> &vis){
        
        if(vis[node]!=-1) return;
        
        vis[node] = d;
        
        if(edges[node]==-1){
            return;
        }
        
        dfs(edges , edges[node] , d+1 , vis);
    }
};