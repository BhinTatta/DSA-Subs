class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans , temp;
        stringstream ss(s);
        while(getline(ss , temp , ' ') ){
            reverse(temp.begin() , temp.end());
            ans += temp;
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};