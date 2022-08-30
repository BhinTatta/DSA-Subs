class KthLargest {
public:
    priority_queue<int> pq;
    int size;
    
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int i : nums){
            if(pq.size()<k){
                pq.push(-i);
            }
            else{
                if(i > -pq.top()){
                    pq.pop();
                    pq.push(-i);
                }
            }
        }
    }
    
    int add(int val) {
        if(pq.size() < size){
            pq.push(-val);
        }
        else if(val > -pq.top()){
            pq.pop();
            pq.push(-val);
         }
        
        return -pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */