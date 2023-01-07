class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0 ; 
        int balance = 0;
        int fuel = 0;
        
        for(int i = 0; i < gas.size() ; i++){
            if(fuel+gas[i]-cost[i] >= 0){
                fuel = fuel+gas[i]-cost[i];
            }
            else{
                start = i+1;
                balance += fuel + gas[i] - cost[i];
                fuel = 0;
            }
            //cout<<balance << " "<<fuel <<endl;
        }
        //cout<<balance << " "<<fuel <<endl;
        if(abs(balance) > fuel) return -1;
        return start;
    }
};