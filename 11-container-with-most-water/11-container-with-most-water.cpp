class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0 , r = n-1;
        int maxarea = INT_MIN;
        while(l<r){
            int lheight = height[l];
            int rheight = height[r];
            int area = min(lheight,rheight) * (r-l);
            
            maxarea = max(maxarea,area);
            
            if(lheight < rheight){
                l++;
            }
            else{
                r--;
            }
        }
        
        return maxarea;
    }
};