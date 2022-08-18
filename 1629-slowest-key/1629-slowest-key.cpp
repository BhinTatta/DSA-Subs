class Solution {
public:
    char slowestKey(vector<int>& time, string keys) {
        priority_queue<pair<int,int>> pq;
        int n = time.size() , last = 0;
        int maxi = INT_MIN , idx = 0;
        for(int i = 0 ; i < n ; i++){
            int press = time[i];
            int taken = press-last;
            if(taken > maxi){
                maxi = taken;
                idx = i;
            }
            else if(taken == maxi){
                keys[idx] > keys[i] ? idx = idx : idx = i;
            }
            last = press;
        }
        return keys[idx];
    }
};