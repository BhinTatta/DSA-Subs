class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        //crate the comparator
        vector<int> comp(26,0);
        
        for(auto word : words2){
            merger(comp , creator(word));
        }
        
        //now the comparetor is created, now let's iterate through the words1 to find universal
        
        vector<string> ans;
        
        for(string word : words1){
            vector<int> curr = creator(word);
            bool flag = false;
            for(int i = 0 ; i < 26 ; i++){
                if(curr[i] < comp[i]){
                    flag = true;
                    break;
                }                
            }
            if(!flag) ans.push_back(word);
        }
        
        return ans;

    }
    
    vector<int> creator(string s){
        vector<int> map(26,0);
        for(auto it : s){
            int pos = it - 'a';
            map[pos]++;
        }
        return map;
    }
    
    void merger(vector<int> &comp , vector<int>word){
        for(int i = 0 ; i < 26 ; i++){
            comp[i] = max(comp[i],word[i]);
        }
    }
};