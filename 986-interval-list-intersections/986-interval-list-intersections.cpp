class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
        int flen = first.size();
        int slen = second.size();
        vector<vector<int>> ans;
        int i = 0 , j = 0;
        while( i < flen && j < slen){
            int s1 = first[i][0] , e1 = first[i][1];
            int s2 = second[j][0] , e2 = second[j][1];
            
            if(s1 <= e2 && s2 <= e1){
                ans.push_back({ max(s1,s2) , min(e1,e2) });
            }
            
            e1 < e2 ? i++ : j++;
        }
        
        return ans;
    }
};