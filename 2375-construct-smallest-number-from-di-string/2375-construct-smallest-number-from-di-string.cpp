class Solution {
public:
    string ans = "z";
    int n;
    string smallestNumber(string pat) {
        n = pat.length()+1;
        vector<int> vis(10,0);
        string temp = "";
        for(int i = 1 ; i < 10; i++){
            helper(pat , 0 , i , vis , temp);
        }
        return ans;
    }
    
    void helper(string &pat, int i , int dig , vector<int>vis , string temp){
        temp.push_back('0'+dig);
        if(temp.length() == n){
            ans = min(ans,temp);
            return;
        }
        if(dig<1 || dig>9) return;
        
        vis[dig]=1;
        
        char move = pat[i];       
        if(move=='I'){
            for(int x = dig+1; x < 10 ; x++) if(vis[x]==0) helper(pat,i+1,x,vis,temp);
        }
        else{
            for(int x = dig-1 ; x >0 ; x--) if(vis[x]==0) helper(pat,i+1,x,vis,temp);
        }
    }
};












