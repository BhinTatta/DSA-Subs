class Solution {
public:
    string reverseWords(string s) {
        vector<string> temp;
        stringstream ss(s);
        string word;
        while(ss>>word){
            temp.push_back(word);
        }
        reverse(temp.begin() , temp.end());
        
        string ans;
        for(string i : temp){
            ans += i;
            ans += " ";
        }
        ans.erase(ans.end()-1);
        return ans;
    }
};