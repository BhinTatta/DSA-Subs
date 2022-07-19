class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        vector<int> curr = {1};
        for(int i = 1 ; i < n+1 ; i++){
            ans.push_back(curr);
            curr.push_back(0);
            curr.insert(curr.begin() , 0);
            // now fill the new vector
            vector<int> temp(i+1);
            temp[0]=1;
            temp[i]=1;
            for(int j = 0 ; j < temp.size() ; j++){
                temp[j] = curr[j+1]+curr[j];
            }
            curr = temp;
        }
        return ans;
    }
};