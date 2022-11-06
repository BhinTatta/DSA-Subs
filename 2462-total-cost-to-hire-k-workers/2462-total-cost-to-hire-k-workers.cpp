class Solution {
public:
    long long totalCost(vector<int>& nums, int k, int candi) {
       
        int n = nums.size();
        int i = candi , j = n-candi-1;
        priority_queue<pair<int,int>> a , b;
        
        for(int i = 0 ; i < candi ; i++){
            a.push({ -nums[i] , -i } );
        }
        for(int i = n-1 ; i >= n-candi; i--){
             b.push({ -nums[i] , -i } );
        }
        
        unordered_map<int,int> taken;
        
        long long int ans = 0;
        int t = 0;
        
        while( n-t>candi && k>0 ){
            while(taken.find((-a.top().second))!=taken.end())a.pop();
            while(taken.find((-b.top().second))!=taken.end())b.pop();
            auto f = a.top() , e = b.top();
            int fval = -f.first , fi = -f.second;
            int eval = -e.first , ei = -e.second;
            
            if(fval <= eval){
                a.pop();
                //cout<<"a"<<" "<<fi<<" "<<nums[fi]<<endl;
                ans += fval;
                taken[fi]++;
                while(i<n && taken.find(i)!=taken.end()){
                    i++;
                }
                if(i<n){
                    a.push( {-nums[i] , -i} );
                    i++;
                }
            }
            else{
                b.pop();
                //cout<<"b"<<" "<<ei<<" "<<nums[ei]<<endl;
                ans += eval;
                taken[ei]++;
                while(j>=0 && taken.find(j)!=taken.end()){
                    j--;
                }
                if(j>=0){
                    b.push( {-nums[j] , -j} );
                    j--;
                }
            }
            k--;
        }
        
        if(k==0) return ans;
        
        priority_queue<pair<int,int>> pq;
        for(int i = 0 ; i < n ; i++){
            if(taken.find(i)==taken.end()){
                pq.push({-nums[i] , -i});
            }
        }
        while(k>0 && !pq.empty()){
            auto curr = pq.top();
            //cout<<"x"<<" "<<-curr.second<<" "<<nums[-curr.second]<<endl;
            pq.pop();
            ans += -1*curr.first;
            k--;
        }
        
        return ans;
    }
};