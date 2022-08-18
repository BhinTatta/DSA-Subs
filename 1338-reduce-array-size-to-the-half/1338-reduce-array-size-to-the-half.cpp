class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int i = n;
        unordered_map<int,int> mp_temp;
        for(int x : arr) mp_temp[x]++;
        priority_queue<int> mp;
        for(auto it : mp_temp){
            mp.push(it.second );
        }
        int ans = 0;
        while(i> n/2){
            i -= mp.top();
            mp.pop();
            ans++;
        }
        return ans;
    }
};