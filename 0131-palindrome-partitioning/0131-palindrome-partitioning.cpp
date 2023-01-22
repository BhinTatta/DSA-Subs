class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        int n = s.length();
        solver(ans,temp,s,n,0);
        return ans;
    }
    
    void solver(vector<vector<string>> &ans , vector<string>temp , string s,int n,int i){
        if(i==n){
            ans.push_back(temp);
            return;
        }        
        for(int j = 1 ; j < n-i+1 ; j++){
            string curr = s.substr(i,j);
            if(ispalin(curr)){
                temp.push_back(curr);
                solver(ans,temp,s,n,i+j);
                temp.pop_back();
            }
        }
    }
    
    bool ispalin(string s){
        int n = s.length();
        int l = 0 , r = n-1;
        while(l <= r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};