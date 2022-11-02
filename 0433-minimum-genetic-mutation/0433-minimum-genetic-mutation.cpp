class Solution {
public:
    unordered_map<string,int> valid;
    char dp[4] = {'A','C','G','T'};
    
    int minMutation(string start, string end, vector<string>& bank) {
        for(string s : bank) valid[s]++;
        int step = 0;
        
        queue<string> q;
        q.push(start);
        unordered_map<string,int> done;
        done[start]++;
        
        while(!q.empty()){
            int size = q.size();
            step++;
            while(size-->0){
                auto curr = q.front();
                q.pop();
                for(int i = 0 ; i < 8 ; i++){
                    for(int j = 0 ; j < 4 ; j++){
                        string temp = curr;
                        temp[i] = dp[j];
                        
                        if(valid.find(temp)!=valid.end()  &&  done.find(temp)==done.end()){
                            done[temp]++;
                            q.push(temp);
                            if(temp==end) return step;
                        }
                    }
                }
            }
        }
        
        
        return -1;
    }
};