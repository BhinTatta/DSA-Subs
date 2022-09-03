class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        if(n==1) return arr;
        
        int idx = lower_bound(arr.begin() , arr.end() , x) - arr.begin();
        if(idx>=n) idx = n-1;
        if(idx>0 && abs(arr[idx-1]-x) <= abs(arr[idx]-x)) idx--;
        int l = idx , r = idx;
        if(r<n-1) r++;
        else l--;
        //cout<<idx<<" "<<l<<" "<<r<<endl;
        while(k-->0){
            int left = 1e6, right = 1e6;
            if(l>=0) left = arr[l];
            if(r<n) right = arr[r];
            //cout<<"-> "<<left<<" "<<right<<endl;
            if(abs(left-x)<=abs(right-x)){
                ans.push_back(left);
                l--;
            }
            else{
                ans.push_back(right);
                r++;
            }
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};