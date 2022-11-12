class MedianFinder {
private:
    priority_queue<int> firstQ; // max_heap for the first half
    priority_queue<int, std::vector<int>, std::greater<int> > secQ; // min_heap for the second half
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if(firstQ.empty() || (firstQ.top()>num)) firstQ.push(num); // if it belongs to the smaller half
        else secQ.push(num); 
        
        // rebalance the two halfs to make sure the length difference is no larger than 1
        if(firstQ.size() > (secQ.size()+1))
        {
            secQ.push(firstQ.top());
            firstQ.pop();
        }
        else if(firstQ.size()+1<secQ.size())
        {
            firstQ.push(secQ.top());
            secQ.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(firstQ.size() == secQ.size()) return firstQ.empty()?0:( (firstQ.top()+secQ.top())/2.0);
        else return (firstQ.size() > secQ.size())? firstQ.top():secQ.top(); 
    }
};
// class MedianFinder {
// public:
//     int size = 0;
//     int n = 0 , m = 0;
//     priority_queue<int> smol;
//     priority_queue<int, vector<int>, greater<int>> big;
//     MedianFinder() {
        
//     }
    
//     void addNum(int num) {      
//         int a = smol.top() , b = big.top();
//         if(num <= a){
//             if(n<=m){
//                 smol.push(num);
//                 n++;
//             }
//             else{
//                 big.push(smol.top());
//             }
//         }
//     }
    
//     double findMedian() {
//         if(n>m){
//             return smol.top();
//         }
//         else{
//             double a = smol.top() , b = big.top();
//             return (a+b)/2;
//         }
//     }
// };

// /**
//  * Your MedianFinder object will be instantiated and called as such:
//  * MedianFinder* obj = new MedianFinder();
//  * obj->addNum(num);
//  * double param_2 = obj->findMedian();
//  */