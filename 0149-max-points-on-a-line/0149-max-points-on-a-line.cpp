class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        //sort(points.begin() , points.end());
        int ans = 0;
        for(int i = 0 ; i < n ; i ++){
            double x = points[i][0] , y = points[i][1];
            int curr = 0;
            unordered_map<double,int> mp;
            for(int j = i+1 ; j < n ; j++){
                double currx = points[j][0] , curry = points[j][1];
                double slope;
                if(currx==x) slope = INT_MAX;
                else slope = (curry-y) / (currx-x);
                mp[slope]++;
            }
            for(auto it : mp){
                curr = max(curr , it.second);
            }
            ans = max(ans,curr);
        }
        return ans+1;
    }
};