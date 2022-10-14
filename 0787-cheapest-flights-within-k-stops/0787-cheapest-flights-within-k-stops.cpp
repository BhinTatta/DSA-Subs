class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int desti, int k) {
        vector<vector<int>> adj[n];
        for(auto it : flights){
            int a = it[0] , b = it[1] , c = it[2];
            adj[a].push_back({b,c});
        }
        // create dist 2d array
        vector<int> dist(n , INT_MAX);
        dist[src] = 0;
        //
        queue<vector<int>> pq;
        pq.push( { 0 , src , 0} );
        
        while(!pq.empty()){
            auto curr = pq.front();
            pq.pop();
            
            int cost =  curr[2] , node = curr[1] , k_curr = curr[0];
            if(k_curr>k) continue;
            for(auto it : adj[node]){
                
                int dst = it[0] , price = it[1];
                int total = price + cost;
                if(total < dist[dst]){
                    dist[dst] = total;
                    pq.push( {k_curr +1 , dst , total } );
                }
                
            }
        }
        
       
        return dist[desti] == INT_MAX ? -1 : dist[desti];
    }
};






