class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>> mp;
        for(auto it : nums){
            int att = it[0];
            int def = it[1];
            mp[att].push_back(def);
        }
        
        priority_queue<pair<int,vector<int>>> pq;
        for(auto it : mp){
            pq.push({it.first , it.second});
        }
        
        int maxi = 0;
        int ans = 0;
        
        while(!pq.empty()){
            auto curr = pq.top();
            //cout<<curr.first<<"  -  "<<curr.second[0]<<" "<<curr.second[1]<<endl;
            auto def = curr.second;
            pq.pop();
            int temp = 0;
            for(auto it : def){
                if(it<maxi) ans++;
                temp = max(it,temp);
            }
            maxi = max(maxi , temp);
        }
        
        return ans;
    }
};