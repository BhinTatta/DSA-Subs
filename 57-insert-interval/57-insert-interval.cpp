class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& my) {
        int mys = my[0] , myend = my[1];
        int n = interval.size();
        
        for(int i = 0 ; i < n ; i ++){
            int currs = interval[i][0];
            int currend = interval[i][1];
            
            if(currs <= mys && currend >= myend) return interval; //when i'm a subset
            
            if(currs < mys && currend < mys) continue;  //skip when not overlap
            if(currs >= mys && currend <= myend) continue;  // skip when they are subset
            
            // when ever we encounter an overlap, increase my boundary
            //his end is in me || my end is in his
            if(currend >= mys && myend > currend){
                mys = currs;
            }
            else if( currs <= myend && currend > myend){
                myend = currend;
            }            
        }
        
        // recreate the answer by neglecting the subsets;
        
        vector<vector<int>> ans;
        ans.push_back({mys,myend});
        for(int i = 0 ; i < n ; i++){
            int currs = interval[i][0];
            int currend = interval[i][1];
            
            if((currs<mys && currend < mys) || (currs > myend && currend > myend) ){
                ans.push_back(interval[i]);
            }
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};