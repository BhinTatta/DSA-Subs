class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& op) {
        unordered_map<int,int> table;
        
        for(int i = 0 ; i <nums.size() ; i++){
            table[nums[i]] = i ;        
        }
        
        for(int i = 0 ; i < op.size() ; i++){
            int find = op[i][0];
            int rep = op[i][1];
            
            int pos = table[find];
            table.erase(find);
            table[ rep ] = pos;
            
            nums[pos] = rep;
        }
        
        
        return nums;
        
    }
};