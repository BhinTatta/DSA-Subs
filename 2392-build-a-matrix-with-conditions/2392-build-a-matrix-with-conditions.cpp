class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowcond, vector<vector<int>>& colcond) {
        vector<int> row = findorder(k+1 , rowcond);
        vector<int> col = findorder(k+1 , colcond);
        // for(int x : row) cout<<x<<" ";
        // cout<<endl;
        // for(int x : col) cout<<x<<" ";
        // cout<<endl;
        if(row.size()!=col.size()) return {};
        
        vector<vector<int>> ans(k, vector<int>(k,0));
        
        for(int i = 1 ; i < k+1 ; i++){
            for(int j = 1 ; j < k+1 ; j++){
                if(row[i]==col[j]) ans[i-1][j-1] = row[i];
            }
        }
        
        return ans;
        
    }
    
    
    vector<int> findorder(int num, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(num);
        vector<int> indeg(num,0);
        for(auto pair : prereq){
            adj[pair[0]].push_back(pair[1]);
            indeg[pair[1]]++;
        }
        
        queue<int> q;
        for(int i = 0 ; i < num ; i++){
            if(indeg[i]==0) q.push(i);
        }
        
        vector<int>ans;
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto course : adj[curr]){
                indeg[course]--;
                if(indeg[course]==0) q.push(course);
            }
        }
        
        if(ans.size() < num) return {};
        return ans;
    }
};