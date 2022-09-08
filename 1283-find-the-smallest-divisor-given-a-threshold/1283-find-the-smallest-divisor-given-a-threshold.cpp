class Solution {
public:
    // literally pasted coco eating banana
    int smallestDivisor(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1 , r = 1e6;
        int ans = INT_MAX;
        while(l<=r){
            int mid = l + (r-l)/2;
            bool mini = helper(piles,mid,h);
            //cout<<l<<" "<<r<<" = "<<mid<<endl;
            if(mini){
                ans = min(mid , ans);
                r = mid-1;
            }
            else{
                l = mid+1;
            }
            
        }
        
        return ans;
    }
    
    bool helper(vector<int>&nums , int k , int h){
        int n = nums.size();
        long long ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans += ceil( (nums[i]*1.0)/k );
        }
        return ans <= h;
    }
};