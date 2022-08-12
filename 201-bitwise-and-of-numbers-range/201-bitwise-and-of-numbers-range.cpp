class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        while(left!=right){
            left = left>>1;
            right = right>>1;
            count++;
        }
        for(int i = 0 ; i < count ; i++){
            left = left<<1;
        }
        return left;
    }
};