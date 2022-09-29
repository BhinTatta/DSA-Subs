class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int>ans(n,INT_MIN);
        int i = n-1;
        while(i>=0){
            int curr = nums[i];
            int j = 1;
            while( (i+j)%n != i){
                int pos = (i+j)%n;
                int temp = nums[pos];
                if(temp>curr){
                    //cout<<curr<<" "<<temp<<endl;
                    ans[i] = temp;
                    mp[curr] = temp;
                    break;
                }
                else if(temp<=curr){
                    if(mp.find(temp)!=mp.end() && mp[temp]==INT_MIN){
                        mp[curr]=INT_MIN;
                        ans[i] = INT_MIN;
                        break;
                    }
                    else if(mp.find(temp)!=mp.end() && mp[temp]>curr){
                        mp[curr] = mp[temp];
                        ans[i] = mp[temp];
                        break;
                    }
                }
                j++;
            }
            if(ans[i]==INT_MIN){
                ans[i]=-1;
            }
            i--;
        }
        
        return ans;
    }
};