class Solution {
public:
    vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<string,int> mp;
        int ans = 0;
        for(string word : words){
            string trans = "";
            for(char alpha : word){
                int pos = alpha -'a';
                trans+= morse[pos];
            }
            if(mp.find(trans)==mp.end()){
                ans++;
                mp[trans]++;
            }
        }
        return ans;
    }
};