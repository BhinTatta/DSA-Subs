class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        st.push({INT_MAX , 0});
    }
    
    int next(int n) {
        int span = 1;
        while(st.top().first <= n){
            span += st.top().second;
            st.pop();
        }
        st.push({n,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */