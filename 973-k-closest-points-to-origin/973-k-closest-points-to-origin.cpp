class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<double,vector<vector<int>>> mp;
        priority_queue<double> pq;
        
        for(auto point : points){
            int x = point[0] , y = point[1];
            double d = pow( (x*x) + (y*y) , 0.5 );
            
            if(pq.size()<k) pq.push(d);
            
            else{
                pq.push(d);
                pq.pop();
            }
            //pq.push(d);
            //cout<<x<<" "<<y<<" "<<d<<endl;
            mp[d].push_back({x,y});
        }
        
        vector<vector<int>> ans;
        unordered_map<double,int> done;
        
        while(!pq.empty()){
            if(done.find(pq.top())==done.end()) for(auto x : mp[pq.top()]) ans.push_back(x);
            //cout<<pq.top()<<" - "<<ans.back()[0]<<" "<<ans.back()[1]<<endl;
            done[pq.top()]++;
            pq.pop();
        }
        // for(int i = 0 ; i < k ; i ++){
        //     ans.push_back(mp[pq.top()]);
        //     cout<<pq.top()<<" - "<<ans.back()[0]<<" "<<ans.back()[1]<<endl;
        //     pq.pop();
        // }
        return ans;
    }
};