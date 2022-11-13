//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    vector<pair<int,int>> arr;
	    for(int i = 0 ; i < n ; i++) arr.push_back({nums[i] , i});
	    sort(arr.begin() , arr.end());
	    int i = 0;
	    int ans = 0;
	    while(i<n){
	        if(arr[i].first != nums[i]){
	            swap(arr[i] , arr[ arr[i].second]);
	            ans++;
	        }
	        else{
	            i++;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends