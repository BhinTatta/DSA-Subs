class Solution {
public:
    int findCircleNum(vector<vector<int>>& citymap) {
        int n = citymap.size();
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n; j++){
                if(j!=i && citymap[i][j]==1) adj[i].push_back(j);
            }
        }
        //cout<<"adj done"<<endl;
        queue<pair<int,int>> q;
        vector<int> vis(n+1 , 0);
        int ans = 0;
        for(int i = 0 ; i < n ; i ++){
            if(vis[i]!=0) continue;          
            ans++;
            q.push({i , -1});
            vis[i]=1;
            while(!q.empty()){
                int city = q.front().first;
                int parent = q.front().second;
                q.pop();
                for(auto neighbr : adj[city]){
                    if(neighbr != parent && vis[neighbr]==0){
                        cout<<city<< " " <<neighbr<<endl;
                        vis[neighbr] = 1;
                        q.push({neighbr , city});
                    }
                }
            }
        }
        
        return ans;
    }
};