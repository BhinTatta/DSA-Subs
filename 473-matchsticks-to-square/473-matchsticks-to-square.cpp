class Solution {
public:
    bool dfs(vector<int> &sidesLength,const vector<int> &matches, int index, const int target) {
        if (index == matches.size())
            return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] && sidesLength[2] == sidesLength[3];
        for (int i = 0; i < 4; ++i) {
            if (sidesLength[i] + matches[index] > target) // first
                continue;
            int j = i;
            while (--j >= 0) // third
                if (sidesLength[i] == sidesLength[j]) 
                    break;
            if (j != -1) continue;
            sidesLength[i] += matches[index];
            if (dfs(sidesLength, matches, index + 1, target))
                return true;
            sidesLength[i] -= matches[index];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int sum = 0;
        for (const int val: nums) {
            sum += val;
        }
        if (sum % 4 != 0) return false;
        sort(nums.begin(), nums.end(), [](const int &l, const int &r){return l > r;}); // second
        vector<int> sidesLength(4, 0);
        return dfs(sidesLength, nums, 0, sum / 4);
    }
//     int n , side;
//     bool makesquare(vector<int>& match) {
//         n = match.size();
//         int i = 0;
//         vector<int> sq = {0,0,0,0};
//         side = 0 ;
//         for(int i = 0 ; i < n ; i++){
//             side += match[i];
//         }
//         if(side%4!=0) return false;
//         side = side/4;
//         sort(match.begin(), match.end(), [](const int &l, const int &r){return l > r;});
//         return helper(match , sq , 0 );
//     }
    
//     bool helper(vector<int> match , vector<int> &sq , int i ){
//         if(!issquare(sq , i)) return false;
//         if( i > n ) return false;
//         if( i == n && issquare(sq , i)) return true;
        
//         bool flag = false;
        
//         for(int x = 0 ; x < 4 ; x++){
//             sq[x]+=match[i];
//             if(sq[x] <= side){
//                 bool ans = helper(match , sq , i+1);
//                 if(ans==true) return ans;
//             }
//             sq[x]-= match[i];
//         }
        
//         return flag;
//     }
    
//     bool issquare(vector<int> sq , int i){
//         //cout<<"i is = "<<i<<endl;
//         for(int i = 0 ; i < 4 ; i++){
//             //cout<<sq[i]<<" ";
//             if(sq[i] > side) return false;
//         }
        
//         return true;
//     }
};