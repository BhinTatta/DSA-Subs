class Solution {
public:
    int maximum69Number (int num) {
        int temp = num , six = -1 , i = 0;
        while(temp){
            if(temp%10 == 6) six = i;
            i++;
            temp /= 10;
        }
        return six == -1 ? num : (num + 3*pow(10,six));
    }
};