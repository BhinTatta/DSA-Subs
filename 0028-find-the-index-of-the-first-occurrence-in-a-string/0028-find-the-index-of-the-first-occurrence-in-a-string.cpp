class Solution {
public:
    int strStr(string hay, string str) {
        int n = hay.size() , m = str.size();
        int i = 0 , j = 0;
        
        while(i < n){
            char curr = hay[i];
            int k = i;
            if(curr == str[0]){
                while(j<m && i<n && hay[i]==str[j]){
                    i++;
                    j++;
                }
                if(j==m){
                    return i-m;
                }
                else{
                    j = 0;
                    i = k+1;
                }
            }
            
            else i++;
        }
        
        return -1;
        
    }
};