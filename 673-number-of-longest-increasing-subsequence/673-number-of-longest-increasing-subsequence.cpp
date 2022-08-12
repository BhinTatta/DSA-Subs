class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int,int>>dp; 
        dp.push_back({1,1});     
        for(int i=1;i<nums.size();i++)
        {
            int len=0;
            int count=0;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])  
                {                                        
                    if(len==dp[j].first)   //if max length we found till now is equal to current length
                    {
                        count+=dp[j].second;// we increment count( no. of combinations)
                    }
                    else if(dp[j].first>len) //if greater len is found
                    {
                        count=dp[j].second; 
                        len=dp[j].first;         //then we set count to this seq count and len(maximum len) to its length 
                    }
                }
            }
            if(count==0)
            {
                dp.push_back({len+1,1});
            }
            else 
                dp.push_back({len+1,count});
        }
        int len=0;
        int count=0;
        for(int i=0;i<dp.size();i++) 
        {
            if(len<dp[i].first)
            {
                len=dp[i].first;
                count=dp[i].second;
            }
            else if(len==dp[i].first)
            {
                count+=dp[i].second;
            }
        }
        return count;
    }
};