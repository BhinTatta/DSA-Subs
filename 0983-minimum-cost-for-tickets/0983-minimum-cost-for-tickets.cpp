class Solution {
private:
    int one , week , month , n;
    vector<int> dp;
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        one = cost[0] , week = cost[1] , month = cost[2];
        dp.resize(366,-1);
        n = days.size();
        
        int ans = helper(days , 0);
        
        return ans;
    }
    
    int helper( vector<int> &nums , int i){
        if(i >= n) return 0;
        if(dp[i]!=-1) return dp[i];
        //cout<<i<<endl;
        int curr = nums[i];
        
        int a = one + helper(nums , i+1);
        
        int j = i;
        while(j<n && nums[j]<curr+7) j++;
        int b = week + helper(nums , j);
        
        int k = i;
        while(k<n && nums[k]<curr+30) k++;
        int c = month + helper(nums , k);
        
        //cout<<i<<" "<<a<<" "<<b<<" "<<c<<endl;
        return dp[i] = min(a , min(b,c));
    }
};