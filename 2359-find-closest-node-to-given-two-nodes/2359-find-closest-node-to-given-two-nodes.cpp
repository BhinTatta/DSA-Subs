class Solution {
private:
    int n;
    vector<int> vis1 , vis2;
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        vis1.resize(n,-1);
        vis2.resize(n,-1);
        // vis1[node1]=0;
        // vis2[node2]=0;
        
        dfs(edges , node1, 0 , false);
        dfs(edges , node2 , 0 , true);
        
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
    
    void dfs(vector<int> &edges , int node , int d , bool state){
        
        if(state && vis2[node]!=-1) return;
        if(!state && vis1[node]!=-1) return;
        if(state) vis2[node] = d;
        if(!state) vis1[node] = d;
        if(edges[node]==-1){
            return;
        }
        dfs(edges , edges[node] , d+1 , state);
    }
};