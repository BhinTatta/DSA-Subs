class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue< pair<int,int> > pq;
        for(auto it : arr){
            pq.push( {abs(it-x) , it} );
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            int a = pq.top().second;
            ans.push_back(a);
            pq.pop();
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};