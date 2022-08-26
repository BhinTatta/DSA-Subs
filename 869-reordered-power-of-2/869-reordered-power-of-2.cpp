class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string num = to_string(n);
        
        long long int maxi = INT_MAX , pow = 1;
        while(pow<=maxi){
            if(helper(num , to_string(pow))) return true;
            pow *= 2;
        }
        return false;
    }
    
    bool helper(string a , string b){
        vector<int> avec(10) , bvec(10);
        for(char x : a)avec[x-'0']++;
        for(char x : b)bvec[x-'0']++;
        return avec == bvec;
    }
};