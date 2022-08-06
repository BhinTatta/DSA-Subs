class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> data = {"abc" , "def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<int> nums;
        vector<string> realans;
        int totdig = digits.length();
        if(totdig == 0)return realans;
        for(int i = 0 ; i < totdig ; i++){
            int num = digits[i]-'0';
            nums.push_back(num);
        }
        
        vector<string> ans;
        for(char it : data[nums[0]-2]){
            string temp = "";
            temp.push_back(it);
            ans.push_back(temp);
        }
        
        for(int i = 0 ; i < totdig-1 ; i++){
            int anssize = ans.size();
            for(int j = 0 ; j < anssize ; j++){
                string temp = ans[j];
                for(char it : data[nums[i+1]-2]){
                    temp.push_back(it);
                    ans.push_back(temp);
                    //cout<<temp<<endl;
                    temp.pop_back();
                }
            }
        }
        
        for(string it : ans){
            if(it.length()==totdig) realans.push_back(it);
        }
        return realans;
    }
};