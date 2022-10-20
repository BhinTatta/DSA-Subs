class Solution {
public:
    unordered_map<char,int> first , last;
    
    vector<int> partitionLabels(string s) {
        int n = s.size();
        
        for(int i = 0 ; i < n ; i++){
            char curr = s[i];
            if(first.find(curr)==first.end()) first[curr] = i;
        }
        for(int i = n-1 ; i >= 0 ; i--){
            char curr = s[i];
            if(last.find(curr)==last.end()) last[curr] = i;
        }
        
        
        vector<int> ans;
        
        int i = 0;
        while(i<n){
            char curr = s[i];
            int j = helper(curr , i , s );
            ans.push_back( j-i+1 );
            i = j+1;
        }
        return ans;
    }
    
    int helper(char curr , int i , string s){
        int n = s.size();
        
        int end = last[curr];
        int j = i;
        while(j<=end){
            char temp = s[j];
            end = max(end , last[temp]);
            j++;
        }
        return end;
    }
};




















