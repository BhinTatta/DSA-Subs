class Solution {
public:
    
    bool helper(vector<int>&dist , double hour , int mid){
        double ans = 0;
        for(int i = 0 ; i < dist.size()-1 ; i++){
            double num = dist[i] , den = mid;
            ans += ceil( num / den );
        }
        double last = dist[dist.size()-1] , div = mid;
        ans += last/div;
        
        //if(mid==3) cout<<ans<<endl;
        
        return ans <= hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();  
        
        if(ceil(hour) < n) return -1;
        
        int l = 1 , r = 1e9;        
        int ans = INT_MAX;        
        while(l<=r){
            
            int mid = l + (r-l)/2;  
            
            if(helper(dist , hour , mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }            
        }   

        return ans;        
    }
};