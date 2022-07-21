class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin() , inter.end());
        int n = inter.size();
        inter.push_back({INT_MAX , INT_MAX});
        int i = 0;
        vector<vector<int>> ans;
        vector<int> vis(n+1 , 0);
        while(i < n){
            if(vis[i]==1){
                i++;
                continue;
            }
            cout<<i<<endl;
            int currs = inter[i][0] , currend = inter[i][1];
            if(currend < inter[i+1][0]){
                ans.push_back({currs , currend});
                i++; 
            }
            else if(currend >= inter[i+1][0]){
                while(currend >= inter[i+1][0]){
                    currend = max(inter[i+1][1] , currend);
                    i++;
                    vis[i]=1;
                    //cout<<i<<" - "<<currs<<" "<<currend<<" "<<endl;
                }
                ans.push_back({currs , currend});
            }
        }
        
        return ans;
    }
};