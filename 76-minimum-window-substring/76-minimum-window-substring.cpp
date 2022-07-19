class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0) return "";
        vector<int> remaining(128, 0);
        int required = t.size();
        for (int i = 0; i < required; i++) remaining[t[i]]++;
        // left is the start index of the min-length substring ever found
        int min = INT_MAX, start = 0, left = 0, i = 0;
        while(i <= s.size() && start < s.size()) {
            if(required) {
                if (i == s.size()) break;
                remaining[s[i]]--;
                if (remaining[s[i]] >= 0) required--;
                i++;
            } else {
                if (i - start < min) {
                    min = i -start;
                    left = start;
                }
                remaining[s[start]]++;
                if (remaining[s[start]] > 0) required++;
                start++;
            }
        }
        return min == INT_MAX? "" : s.substr(left, min);
    }
//     unordered_map<char , int> smap , tmap;
//     queue<int> q;
    
//     string minWindow(string s, string t) {
//         int m = s.length() , n = t.length();
//         string ans = s+"hehe";
//         if(n>m) return "";
//         int l = 0 , r = 0;
        
//         for(int i = 0 ; i < n ; i++){
//             tmap[t[i]]++;
//         }
        
//         if(m==1 && n==1){
//             s==t ? ans = s : ans ="";
//             return ans;
//         }
//         //here run the sliding window
//         while(r < m){
//             char curr = s[r];
//             smap[curr]++;
            
//             //if(tmap[curr]) q.push(r); // push in q if belongs;
//             if(r-l+1 >= n){               // check for same string
//                 print(smap);
//                 while(is_wind(smap , tmap)==true){  // while true reduce the window
//                     string currstr = s.substr(l , r+1);
                    
//                     cout<<currstr<<"  =  ";
//                     print(smap);
//                     ans.length() > currstr.length() ? ans = currstr: ans = ans;
//                     cout<<" Ans is = "<<ans<<endl;
//                     // cout<<t<< " = ";
//                     // print(smap);
//                     //cout<<"  dekh o ->"<<tmap[s[l]];
//                     smap[l]--;
//                     l++;
//                 }
//             }
            
//             r++;
//         }
        
        
//         ans.length() > m ? ans = "" : ans = ans;
//         return ans;
        
//     }
        
//     void print(unordered_map<char , int> mp){
//         for(auto it : mp){
//             cout<<it.first;
//         }
//         cout<<endl;
//     }  
        
//     bool is_wind(unordered_map<char , int> smap , unordered_map<char , int> tmap){
        
//         for(auto t : tmap){
//             char curr = t.first;
//             cout<<curr<<" - "<<t.second<<" "<<endl;
//             if(smap[curr]<t.second) return false;
//         }
//         return true;
//     }
    

};