class Solution {
public:
    int n;
    vector<int> searchRange(vector<int>& nums, int target) {
        n = nums.size();
        if(n==0) return vector<int>{-1,-1};
        int left = findmin(nums,target);
        int right = findmax(nums,target);
        vector<int> ans = {left,right};
        return ans;
    }
    
private:
    int findmin(vector<int>& nums, int target){
        int minpos = n;
        
        int l = 0 , r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
            int curr = nums[mid];
            if(curr<target) l = mid+1;
            else if(curr>target) r = mid-1;
            else if(curr==target){
                minpos = min(mid , minpos);
                r = mid-1;
            }
        }
        return minpos == n ? -1 : minpos;
    }
    int findmax(vector<int>& nums, int target){
        int maxpos = -1;
        
        int l = 0 , r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
            int curr = nums[mid];
            if(curr<target) l = mid+1;
            else if(curr>target) r = mid-1;
            else if(curr==target){
                maxpos = max(mid , maxpos);
                l = mid+1;
            }
        }
        return maxpos == -1 ? -1 : maxpos;
    }
};