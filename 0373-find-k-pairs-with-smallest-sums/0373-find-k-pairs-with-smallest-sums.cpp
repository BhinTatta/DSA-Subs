class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size() , m = nums2.size();
        priority_queue<pair<int,int>> pq;
        
        for(int i = 0 ; i < n ; i++){
            int a = nums1[i];
            for(int j = 0 ; j < m ; j++){
                int b = nums2[j], sum = a+b;
                
                if(pq.size()<k)pq.push({sum,a});
                else if(pq.top().first>sum){
                    pq.pop();
                    pq.push({sum,a});
                }
                else break;
            }
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()){
            int sum = pq.top().first, a = pq.top().second , b = sum-a;
            ans.push_back( {a, b} );
            pq.pop();
        }
        
        return ans;
    }
};