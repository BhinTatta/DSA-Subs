class Solution {
public:
    bool isRobotBounded(string inst) {
        int dir = 0;
        double x1 = 0 , y1 = 0;
        mover(inst , x1 , y1 , dir);
        
        double x2 = x1 , y2 = y1;
        mover(inst , x2 , y2 , dir);
        
        double slope1 , slope2;
        if(x1==0) y1 < 0 ?  slope1 = INT_MIN : slope1 = INT_MAX;
        else slope1 = y1/x1;
        
        if(x2==0) y2 < 0 ?  slope2 = INT_MIN : slope2 = INT_MAX;
        else slope2 = (y2-0)/(x2-0);

        if(x1==x2 && y1==y2 || (x2==0 && y2==0)) return true;
        if(slope1==slope2) return false;
        return true;
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