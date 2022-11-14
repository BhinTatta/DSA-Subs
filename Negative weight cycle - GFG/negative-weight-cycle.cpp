//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dist(n,1e8);
        dist[0] = 0;
	    for(int i = 1 ; i < n ; i++){
    	    for(auto it : edges){
    	        int a = it[0] , b = it[1] , d = it[2];
    	        if(dist[a]+d < dist[b]) dist[b] = dist[a] + d; 
    	    }
	    }
	    vector<int> temp = dist;
	    for(auto it : edges){
	        int a = it[0] , b = it[1] , d = it[2];
    	        if(temp[a]+d < temp[b]) temp[b] = temp[a] + d; 
	    }
	    
	    for(int i = 0 ; i < n ; i++){
	        if(dist[i]!=temp[i]){
	           // vector<int>ans(n,-1);
	            return 1;
	        }
	    }
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends