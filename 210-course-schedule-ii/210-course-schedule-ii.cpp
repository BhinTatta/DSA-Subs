class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& prereq) {
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
        
        reverse(ans.begin() , ans.end());
        if(ans.size() < num) return {};
        return ans;
    }
};