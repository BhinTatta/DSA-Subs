class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        int n = chars.size() , i = 0 , x = 0;
        while(i<n){
            int j = i+1;
            char curr = chars[i];
            while(j<n && chars[j]==curr) j++;
            int len = j-i;
                        
            if(len==1){
                chars[x] = curr;
                x++;
                ans++;
            }       
            else{
                string s = to_string(len);
                ans += s.length()  + 1;
                chars[x]=curr;
                x++;
                for(char it : s){
                    chars[x]=it;
                    x++;
                }
            }
            i = j;
        }
        //cout<<ans<<endl;
        return ans;
    }
};