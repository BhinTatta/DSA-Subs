class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> data(32,0);
        uint32_t ans = 0;
        int i = 0;
        while(i<32){
            if( (n>>i)&1 != 0 ) data[i] = 1;
            //cout<<data[i]<<" ";
            i++;
        }
        for(int i = 31 ; i > -1 ; i--){
            if(data[i]){
                ans += pow(2 , 31-i);
            }
        }
        return ans;
    }
};