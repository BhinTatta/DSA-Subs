class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i : stones) pq.push(i);
        
        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int w = abs(a-b);
            if(w>0) pq.push(w);
        }
        
        if(pq.empty()) return 0;
        return pq.top();
    }
};