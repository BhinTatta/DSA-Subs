class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        stack<pair<int,int>> st;
        vector<int> left(n);
        st.push({INT_MIN,-1});
        for(int i = 0 ; i < n ; i++){
            int curr = arr[i];
            while(st.top().first > curr)st.pop();
            left[i] = st.top().second;
            st.push({curr,i});
            //cout<<left[i]<<" ";
        }
        //cout<<endl;
        stack<pair<int,int>> st1;
        vector<int> right(n);
        st1.push({INT_MIN,n});
        for(int i = n-1 ; i >=0 ; i--){
            int curr = arr[i];
            while(st1.top().first >= curr)st1.pop();
            right[i] = st1.top().second;
            st1.push({curr,i});
            //cout<<right[i]<<" ";
        }
        //cout<<endl;
        long long int ans = 0;
        for(int i = 0 ; i < n ; i++){
            int l , r;
            left[i]==-1 ? l = i : l = i-left[i]-1;
            right[i]==n ? r = n-i-1 : r =  right[i]-i-1;
            long long int x = ((l+1)*(r+1))%mod;
            ans += arr[i] * ( x  );
            ans = ans%mod;
            //cout<<l<<" "<<r<<" "<<((l+1)*(r+1))<<" "<<ans<<endl;
        }
        return ans;
    }
};