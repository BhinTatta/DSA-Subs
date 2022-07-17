class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q_size = queries.size();
        vector<int> ans;
        for(auto q : queries){
            int pos = q[0];
            int trim = q[1];
            priority_queue< pair<string , int> > pq;
            
            for(int i = 0 ; i < n ; i++){
                string num = nums[i];
                string req_num = num.substr( num.length()-trim , num.length() );
                //reverse(req_num.begin() , req_num.end());
                pq.push( make_pair(req_num , i) );
            }
            //cout<<endl;
            while( pq.size() > pos ){
                //cout<<pq.top().first<<" "<<pq.top().second<<"    ";
                pq.pop();
            }
            //cout<<pq.top().first<<" "<<pq.top().second<<"    ";
            ans.push_back(pq.top().second);
            //cout<<endl<<"---------------------  "<<endl;
        }
        
        return ans;
    }
};