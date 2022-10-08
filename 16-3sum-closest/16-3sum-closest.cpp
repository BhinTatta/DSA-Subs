class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        
        int close = INT_MAX;
        int sum = 0;
        for(int i = 0 ; i < n-2 ; i ++){
            int curr = nums[i];
            int l = i+1 , r= n-1;
            while(l < r){
                if(l==i || r==i){
                    l==i ? l++ : r--;
                    continue;
                }
                
                int currsum = curr + nums[l] + nums[r];
                int currdist = abs( target - currsum );
                if(currdist < close){
                    sum = currsum;
                    close = currdist;
                }
                if(currsum==target) return target;
                if(currsum < target) l++;
                else r--;
            }
        }
        return sum;
    }
};