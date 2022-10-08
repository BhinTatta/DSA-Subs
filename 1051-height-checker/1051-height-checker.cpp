class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> diff(heights.begin(),heights.end());
        sort(heights.begin(),heights.end()); 
      
        int count=0;
        for(int i=0;i<heights.size();i++)
        {
            if(heights[i]!=diff[i])
            {
                count++;
            }
        }
        return count;
    }
};