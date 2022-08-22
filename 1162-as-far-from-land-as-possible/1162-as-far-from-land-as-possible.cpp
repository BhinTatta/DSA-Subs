class Solution {
public:
    int n;
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};
    
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        int ans = -1;
        queue<pair<int,int>> q;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j]==1){
                    
                        q.push({ i , j });
           
                }
            }
        }
       if(q.size() == n*n) return -1;
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            steps++;
            while(size-->0){
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;
                for(int x = 0 ; x < 4 ; x++){
                    int newr = r + drow[x];
                    int newc = c + dcol[x];
                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==0){
                        q.push({newr , newc});
                        grid[newr][newc] = steps;
                    }
                }
            }
        }
    
        return steps-1;
    }
    
    // int helper( vector<vector<int>>& grid , int i , int j ){
    //     int vis[n][n];
    //     memset(vis , 0 , sizeof(vis));
    //     vis[i][j]=1;
    //     queue<pair<int,int>> q;
    //     q.push({i,j});
    //     int mini = 200;
    //     while(!q.empty()){
    //         bool flag = false;
    //         auto curr = q.front();
    //         q.pop();
    //         int r = curr.first;
    //         int c = curr.second;
    //         vis[r][c]=1;
    //         for(int x = 0 ; x < 4 ; x++){
    //             int newr = r + drow[x];
    //             int newc = c + dcol[x];
    //             if(newr < 0 || newr >= n || newc < 0 || newc >= n) continue;
    //             else if(vis[newr][newc]==0){
    //                 if (grid[newr][newc]==1){
    //                     vis[newr][newc]=1;
    //                     mini = min(mini , abs(newr-i) + abs(newc-j));
    //                     flag = true;
    //                     break;
    //                     //cout<<"from "<<i<<" "<<j<<" to "<<newr<<" "<<newc<<" = "<<mini<<endl;
    //                 }
    //                 else{
    //                     //cout<<"from "<<i<<" "<<j<<" to "<<newr<<" "<<newc<<endl;
    //                     q.push({newr,newc});
    //                 }
    //             }
    //         }
    //         if(flag) break;
    //     }
    //     //cout<< "---------------------"<<endl;
    //     return mini;
    // }
};















