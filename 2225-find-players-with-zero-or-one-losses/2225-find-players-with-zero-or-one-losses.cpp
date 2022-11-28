class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> loss , win;
        for(auto it : matches){
            int w = it[0] , l = it[1];
            loss[l]++;
            win[w]++;
        }
        for(auto it : matches){
            int l = it[1];
            if(win.find(l)!=win.end()){
                win.erase(l);
            }
        }
        vector<int> w , l;
        for(auto it : win) w.push_back(it.first);
        for(auto it : loss) if(it.second==1) l.push_back(it.first);
        vector<vector<int>> ans;
        sort(begin(w) , end(w));
        sort(begin(l) , end(l));
        ans.push_back(w);
        ans.push_back(l);
        return ans;
    }
};