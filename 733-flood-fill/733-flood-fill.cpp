class Solution {
public:
    int n , m;
    int row[4] = {-1,0,1,0};
    int col[4] = {0,1,0,-1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vector<vector<int>> vis(m,vector<int>(n,0));
        paint(image,q,color,vis);
        return image;
    }
    
    void paint(vector<vector<int>>& image, queue<pair<int,int>>q , int color,vector<vector<int>> &vis){
        if(q.empty()) return;
        int size = q.size();
        queue<pair<int,int>> newq;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            //cout<<q.size()<<" ";
            int r = curr.first;
            int c = curr.second;
            int mycolor = image[r][c];
            image[r][c] = color;
            vis[r][c]=1;
            for(int i = 0 ; i < 4 ; i ++){
                int newr = r + row[i];
                int newc = c + col[i];
                if(isvalid(image,mycolor,newr,newc,vis)){
                    //cout<<newr<<" "<<newc<<"   ";
                    newq.push({newr,newc});
                }
            }
        }
        paint(image,newq,color,vis);
    }
    
    bool isvalid(vector<vector<int>>& image, int color , int r , int c , vector<vector<int>> &vis){
        if(r<0 || c<0 || r>=m || c>=n) return false;
        if(image[r][c]==color && vis[r][c]==0) return true;
        return false;
    }
};