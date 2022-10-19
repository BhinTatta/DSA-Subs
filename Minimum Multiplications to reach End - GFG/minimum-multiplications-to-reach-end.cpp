//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int dist[100000];
        int mod = 100000;
        for(int i = 0 ; i < 100000 ; i++) dist[i]=INT_MAX;
        dist[start] = 0;
        queue<pair<int,int>> pq;
        pq.push({0,start});
        while(!pq.empty()){
            auto curr= pq.front();
            pq.pop();
            int step = curr.first , node = curr.second;
            for(auto i : arr){
                long long int val = (node * i)%mod;
                if(dist[val] > step+1){
                    dist[val] = step + 1;
                    pq.push({ (step+1) , val});
                }
            }
        }
        
        return dist[end] == INT_MAX ? -1 : dist[end];
    }
    
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends