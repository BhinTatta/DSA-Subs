class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        set<vector<int>> ans;
        int n = nums.size();
        unordered_map<int , vector<int>> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]].push_back(i);
        }
        unordered_map<int,int> imap;
        for(int i = 0 ; i < n-2 ; i++){ 
            if(imap[nums[i]]) continue;
            imap[nums[i]]++;
            for(int  j = i+1 ; j < n-1 ; j++){  
               bool flag = false;
               int req = -1 * (nums[i]+nums[j]);
                if(mp.find(req)!= mp.end()){
                    for(auto it : mp[req]){
                        if(it > i && it > j){
                            ans.insert({ nums[i],nums[j],nums[it] });
                            break;                           
                        }
                    }
                }
            }           
        }
       vector<vector<int>> answer;
        for(auto it : ans){
            answer.push_back(it);
        }
        return answer;
    }
};