class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.size();
        vector<int> yes , no;
        yes.push_back(0);
        no.push_back(0);
        int y = 0;
        for(int i = 0 ; i < n ; i++){
            char curr = s[i];
            if(curr=='N') y++;
            yes.push_back(y);
        }
        int ni = 0;
        for(int i = n-1 ; i>= 0 ; i--){
            char curr = s[i];
            if(curr=='Y') ni++;
            no.push_back(ni);
        }
        
        reverse(no.begin() , no.end()); 
        
        int ans = INT_MAX;
        int val = INT_MAX;
        for(int i = 0 ; i <= n ; i++){
            int pan = no[i] + yes[i];
            if(pan<val){
                ans = i;
                val = pan;
            }
            
        }
        return ans;
    }
};