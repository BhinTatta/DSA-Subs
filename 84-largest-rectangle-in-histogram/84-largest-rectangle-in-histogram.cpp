class Solution {
public:
    void premin(vector<int> &pre , vector<int> hi , int n){
        
        stack<int> st;
        st.push(-1);
        
        for(int i = 0 ; i < n ; i++){
            int curr = hi[i];
            
            while(st.top()!= -1 && curr<=hi[st.top()] ){
                st.pop();
            }
            
            pre[i] = st.top();
            //cout<<pre[i]<<" ";
            st.push(i);
        }
        cout<<endl;
    }
    
    void nextmin(vector<int> &next , vector<int> hi , int n){
        
        stack<int> st;
        st.push(-1);
        
        for(int i = n-1 ; i >=0  ; i--){
            int curr = hi[i];
            
            while(st.top()!= -1 && curr<=hi[st.top()] ){
                st.pop();
            }
            
            
            next[i] = st.top();
            //cout<< next[i] <<" ";
            st.push(i);
        }
        cout<<endl;
    }
    
    int largestRectangleArea(vector<int>& hi) {
        int n = hi.size();
        vector<int> pre(n);
        vector<int> next(n);
        
        
        premin(pre,hi, n);
        nextmin(next,hi,n);
        int area = 0;
        
        for(int i=0; i<n; i++) {
            int l = hi[i];
            
            if(next[i] == -1) {
                next[i] = n;
            }
            int b = next[i] - pre[i] - 1;
            //cout<< l << "  and b = " <<next[i] <<" - "<<  pre[i] <<endl;
            int newArea = l*b;
            area = max(area, newArea);

        }
        return area;
        
    }
};