class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        unordered_map<int,int> mp;
        int ans = 0 , maxi = 0 , i = n-1;
        
        while(i>=0){
            int curr = time[i];
            int x = 1;
            int temp = 0;
            while((60*x)-curr <= maxi){
                int req = 60*x - curr;
                if(mp.find(req)!=mp.end()) temp+=mp[req];
                x++;
            }
            maxi = max(maxi,curr);
            mp[curr]++;
            ans+=temp;
            i--;
        }
        return ans;
    }
};