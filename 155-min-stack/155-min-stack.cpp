class MinStack {
public:
    stack<int> main;
    stack<int> minst;
    
    MinStack() {
        minst.push(INT_MAX);
    }
    
    void push(int val) {
        main.push(val);
        if(val < minst.top()) minst.push(val);
        else minst.push(minst.top());
    }
    
    void pop() {
        main.pop();
        minst.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */