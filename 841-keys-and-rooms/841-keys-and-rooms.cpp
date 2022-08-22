class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int vis[n];
        memset(vis , 0 , sizeof(vis));
        vis[0]=1;
        queue<int> q;
        for(int i : rooms[0]){
            q.push(i);
        }        
        while(!q.empty()){
            int size = q.size();
            while(size-->0){
                int curr = q.front();
                q.pop();
                vis[curr]=1;
                for(int key : rooms[curr]){
                    if(vis[key]==0) q.push(key);
                }
            }
        }
        
        for(int it : vis) if( it == 0) return false;
        return true;
        
    }
};