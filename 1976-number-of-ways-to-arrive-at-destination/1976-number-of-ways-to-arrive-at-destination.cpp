class Solution {
public:
    #define ll long long
    
    ll mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        //int n = roads.size();
        vector<vector<ll>> adj[n];
        for(auto it : roads){
            ll a = it[0] , b = it[1] , c = it[2];
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        
        ll dist[201];
        ll ways[201];
        for(int i = 0 ; i < 201 ; i++){
            dist[i] = LONG_MAX;
            ways[i] = 0;
        }
        
        ll ans = 0;
        dist[0] = 0;
        ways[0] = 1;
        
        priority_queue<pair<ll,ll> , vector<pair<ll,ll>> , greater<pair<ll,ll>> > q;
        q.push( {0,0} );
      
        while(!q.empty()){
            auto curr = q.top();
            q.pop();
            ll dis = curr.first , node = curr.second;
          
            for(auto i : adj[node]){
                
                ll x = i[0] , d = i[1];
                
                if(dist[x] > dis + d){
                    dist[x] = dis + d;
                    ways[x] = ways[node];
                    q.push({(dis+d) , x});
                }
                else if(dist[x] == dis+d){
                    ways[x] = (ways[x] +  ways[node]) % mod;
                }
            }
        }
        
        return ways[n-1]%mod;
        
    }
};