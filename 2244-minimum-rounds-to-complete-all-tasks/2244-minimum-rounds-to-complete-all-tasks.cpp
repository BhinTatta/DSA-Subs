class Solution {
public:

    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(int i : tasks) mp[i]++;
        int ans = 0;
        
        for(auto it : mp){
            int x = it.second;
            if(x==1) return -1;
            ans += (x+2)/3;
        }
        
        return ans;
    }

};