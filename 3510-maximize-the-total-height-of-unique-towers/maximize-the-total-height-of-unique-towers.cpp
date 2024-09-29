class Solution {
public:
    long long maximumTotalSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        long long int ans = 0;
        unordered_map<int,int> mp;
        unordered_map<int , int> cache;
        
        for(int i = n-1 ; i >= 0 ; i--){
            int curr = nums[i];
            
            if(cache.find(curr)!=cache.end()){
                int val = cache[curr];
                val--;
                // cout<<curr<<" cache = "<<val<<endl;
                if(val<1){
                    return -1;
                }else{
                    cache[curr] = val;
                    mp[val] = 1;
                    ans += val;
                    continue;
                }
            }
            
            int req = curr;
            
            while(req>0){
                // cout<<curr<<" mp = "<<req<<endl;
                if( mp.find(req) == mp.end() ){
                    ans += req;
                    mp[req]=1;
                    cache[curr] = req; 
                    break;
                }
                req--;
            }
            if(req == 0){
                return -1;
            }
        }
        
        return ans;
    }
};