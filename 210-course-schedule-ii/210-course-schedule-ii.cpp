class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(n);
        vector<int> indg(n);
        for(int i = 0 ; i < prereq.size() ; i ++){
            adj[prereq[i][0]].push_back(prereq[i][1]);
            indg[prereq[i][1]]++;
        }
        queue<int> q;
        for(int i = 0 ; i < n ; i++ ){
            if(indg[i]==0) q.push(i);
        }
        
        vector<int>ans;
        while(!q.empty()){
            int curr = q.front();
            ans.push_back(curr);
            q.pop();
            
            for(auto it : adj[curr]){
                indg[it]--;
                if(indg[it]==0) q.push(it);
            }
        }
        reverse(ans.begin() , ans.end());
        vector<int> temp;
        return ans.size()==n ? ans : temp;
    }
};