class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin() , points.end());
        int ans = 0;
        // double a = 1 , b = 4 , c = 9 , d = 5;
        // cout<<(a-b)/(c-d);
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
                //cout<< x <<"-"<< y <<" point="<< currx<<"-"<<curry <<  " slope = "<<slope<<endl;
            }
            for(auto it : mp){
                curr = max(curr , it.second);
                //cout<<it.second<<endl;
            }
            //cout<<curr<<endl;
            ans = max(ans,curr);
        }
        return ans+1;
    }
};