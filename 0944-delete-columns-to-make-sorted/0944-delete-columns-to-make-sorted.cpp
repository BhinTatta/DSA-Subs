class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size() , l = strs[0].size();
        int ans = 0;
        
        for(int i = 0 ; i < l ; i++){
            int mini = 0;
            for(int j = 0 ; j < n ; j++){
                int curr = strs[j][i] - 'a';
                if(curr<mini){
                    ans++;
                    break;
                }
                mini = curr;
            }
        }
        return ans;
    }
};