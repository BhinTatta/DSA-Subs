class Solution {
private:
    void same(string &s , int a , int b , char curr){
        for(int i = a ; i <= b ; i++){
            s[i] = curr;
        }
    }
    
    void fall(string &s , int a , int b){
        while(a<b){
            s[a]='R';
            s[b]='L';
            a++;
            b--;
        }
    }
    
    void fill(string &s , int l){
        while(l>=0 && s[l]=='.'){
            s[l]='L';
            l--;
        }
    }
    
public:
    string pushDominoes(string s) {
        int n = s.length();
        int r = -1 , l = 0;
        string ans = s;
        
        while(l<n){
            char curr = s[l];
            if(curr == '.'){
                l++;
                continue;
            }
            else if(curr == 'L'){
                if(r == -1) fill(ans,l-1);
                else fall(ans,r,l);
                r = -1;
            }
            else{
                if(r != -1) same(ans,r,l,'R');
                r = l;
            }
            l++;
        }
        if(r!=-1){
            while(r<n){
                ans[r]='R';
                r++;
            }
        }
        return ans;
    }
};