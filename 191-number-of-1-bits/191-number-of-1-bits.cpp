class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        int i = 0;
        while(i<32){
            if( (n>>i)&1 != 0 ) ans++;
            i++;
        }
        return ans;
    }
};