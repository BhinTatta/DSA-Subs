class Solution {
private:
    
    bool helper(string &s, string &p, vector<int>& nums , int mid){
        int n = s.length();
        int m = p.length();
        //cout<<mid<<endl;
        // making map
        unordered_map<int,int> mp;
        for(int i = 0 ; i < mid ; i++){
            mp[nums[i]]++;
        }
        
        int i = 0 , j = 0;
        while(i<n && j<m){
            if(mp.find(i) != mp.end()){
                i++;
                continue;
            }
            if(s[i]==p[j]) j++;
            i++;
        }
        
        return j==m;
    }
    
public:
    
    int maximumRemovals(string s, string p, vector<int>& nums) {
        int n = s.length();
        int m = p.length();
        
        int l = 0 , r = nums.size();
        int ans = INT_MIN;
        while(l<=r){
            int mid = (r+l)/2;
            bool temp = helper(s,p,nums,mid);
            if(temp){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }

};