class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int a = -1 , b = -1 , c1 = 0 , c2 = 0;
        for(int i : nums){
            if(i==a) c1++;
            else if(i==b) c2++;
            else if(c1 == 0){
                a = i;
                c1 = 1;
            }
            else if(c2==0){
                b = i;
                c2 = 1;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1 = 0 , c2 = 0;
        for(int i : nums){
            if(i==a)c1++;
            if(i==b)c2++;
        }
        
        vector<int> ans;
        
        if(c1>n/3) ans.push_back(a);
        if(a!=b && c2>n/3) ans.push_back(b);
        
        return ans;
    }
};