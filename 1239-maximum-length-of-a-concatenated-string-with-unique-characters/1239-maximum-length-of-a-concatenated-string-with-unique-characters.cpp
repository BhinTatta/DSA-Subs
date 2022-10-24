class Solution {
public:
    int n;
    int freq[26];
    
    int maxLength(vector<string>& arr) {
        memset(freq , 0 , sizeof(freq));
        n = arr.size();
        string temp = "";
        int ans = helper(arr,0,temp);
        return ans;
    }
    
    int helper(vector<string>&arr , int i , string temp){
        if(i>=n) return temp.length();
        
        int dont = helper(arr,i+1,temp);
        int take = 0;
        if(valid(arr[i])){
            for(char it : arr[i]){
                freq[it-'a']++;
            }
            take = helper(arr,i+1, temp+arr[i] );
            for(char it : arr[i]){
                freq[it-'a']--;
            }
        }
        return max(take,dont);
    }
    
    bool valid(string &s){
        bool flag = true;
        int temp[26];
        memset(temp,0,sizeof(temp));
        
        for(char it : s){
            if(freq[it-'a'] > 0 || temp[it-'a']>0) return false;
            temp[it-'a']++;
        }
        return true;
    }
};