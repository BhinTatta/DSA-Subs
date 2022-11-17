class Solution {
public:
    int call(int x1,int x2,int x3,int x4)
    {
        if(x2<x3||x1>x4)return 0;
        int x=abs(min(x2,x4)-max(x1,x3));
        return x;
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int x=abs(ax1-ax2)*abs(ay1-ay2);
        int y=abs(bx1-bx2)*abs(by1-by2);
        int ans=x+y;
        ans-=call(ax1,ax2,bx1,bx2)*call(ay1,ay2,by1,by2);
        return ans;
    }
};