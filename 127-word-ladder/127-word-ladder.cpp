class Solution {
public:
    unordered_map<string,int> mp;
    unordered_map<string , int> done;
    
    int ladderLength(string beg, string end, vector<string>& words) {
        for(auto it : words) mp[it]++;
        if(mp.find(end)==mp.end()) return 0;
        
        return bfs(beg,end);
        
    }
    
    int bfs(string &beg , string&end){
        int n = beg.size();
        queue<string> q;
        q.push(beg);
        int ans = 0;
        bool flag = false;
        while(!q.empty()){
            ans++;
            int size = q.size();
            while(size-->0){
                string curr = q.front();
                if(curr==end){
                    flag = true;
                    return ans;
                }
                q.pop();
                done[curr]++;
                for(int i = 0 ; i < n ; i++){
                    for(int j = 0 ; j < 26 ; j++){
                        string temp = curr;
                        temp[i] = char('a'+j);
                        if( mp.find(temp)!=mp.end() && done.find(temp)==done.end() ){
                            q.push(temp);
                            done[temp]++;
                        }
                    }
                }
            }
            
        }
        return 0;
    }
};