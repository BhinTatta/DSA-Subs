class LUPrefix {
public:
    int lng = 0;
    vector<int> db;
    unordered_map<int,int> mp;
    LUPrefix(int n) {
        db.resize(n+1,0);
    }
    
    void upload(int video) {
        db[video]++;
        mp[video]++;
    }
    
    int longest() {
        while(mp.find(lng+1)!=mp.end()) lng++;
        return lng;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */