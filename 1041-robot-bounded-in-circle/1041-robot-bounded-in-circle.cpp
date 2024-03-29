class Solution {
public:
    bool isRobotBounded(string inst) {
        int dir = 0;
        double x1 = 0 , y1 = 0;
        for(int i = 0 ; i < 4 ; i++ ) mover(inst , x1 , y1 , dir);
        return (x1==0 && y1==0);
    
    }
    
    void mover(string &s , double &x1 , double &y1 , int &dir){
        vector<vector<int>> direct;
        direct.push_back({0,1});
        direct.push_back({1,0});
        direct.push_back({0,-1});
        direct.push_back({-1,0});
        for(int i = 0 ; i < s.size() ; i++){
            char curr = s[i];
            if(curr=='G'){
                x1 += direct[dir][0];
                y1 += direct[dir][1];
            }
            else if(curr == 'L'){
                dir = (dir+3)%4;
            }
            else if(curr == 'R'){
                dir = (dir+1)%4;
            }
        }

    }
};