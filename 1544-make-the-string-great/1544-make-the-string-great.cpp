class Solution {
private:
    int diff = abs('a'-'A');
    
    bool valid(string s){
        if(s=="") return false;
        
        for(int i = 0 ; i < s.length()-1 ; i++){
            if(abs( s[i] - s[i+1] ) == diff) return true;
        }
        
        return false;
    }
    
    string helper(string s){
        int n = s.length();
        string ans = "";
        for(int i = 0 ; i < n-1 ; i++){
            if(abs(s[i] - s[i+1]) == diff){
                for(int j = 0 ; j < n ; j++){
                    if(j!=i && j!=i+1) ans.push_back(s[j]);
                }
                return ans;
            }
        }
        return ans;
    }
public:
    string makeGood(string s) {
        int n = s.size();
        while(valid(s)){
            // cout<<s<<" ";
            s = helper(s);
        }
        return s;
    }
};