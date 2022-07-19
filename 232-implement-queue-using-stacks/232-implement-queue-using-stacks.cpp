class MyQueue {
public:
    stack<int> main;
    stack<int> temp;
    int peeker;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(main.empty()) peeker = x;
        main.push(x);
    }
    
    int pop() {
        while(!main.empty()){
            temp.push(main.top());
            main.pop();
        }
        int curr = temp.top();
        temp.pop();
        if(!temp.empty()) peeker = temp.top();
        while(!temp.empty()){
            main.push(temp.top());
            temp.pop();
        }
        return curr;
    }
    
    int peek() {
        return peeker;
    }
    
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */