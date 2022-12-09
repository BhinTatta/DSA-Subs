class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin() , skill.end());
        int n = skill.size();
        int i = 0 , j = n-1;
        int curr = skill[i]+skill[j];
        long long int ans = 0;
        while(i<j){
            int x = skill[i] + skill[j];
            if(x!=curr) return -1;
            ans += skill[i] * skill[j];
            i++;
            j--;
        }
        return ans;
    }
};