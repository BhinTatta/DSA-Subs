class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truck) {
        priority_queue<pair<int,int>> pq;
        for(auto box : boxTypes){
            pq.push({box[1] , box[0]});
        }
        int ans = 0;
        while(truck > 0 && !pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int boxes = curr.second;
            int units = curr.first;
            if(boxes <= truck){
                ans += units * boxes;
                truck -= boxes;
            }
            else{
                ans += truck*units;
                truck = 0;
            }
        }
        return ans;
    }
};