//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int n, vector<vector<int>>& edges, int S) {
        vector<int> dist(n,1e8);
        dist[S] = 0;
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
	            return {-1};
	        }
	    }
	    return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends