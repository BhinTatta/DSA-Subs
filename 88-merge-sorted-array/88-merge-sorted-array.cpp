class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        if(m==0 && n!=0){
            nums1=nums2;
            return;
        }
        int a[m];
        for(int i = 0 ; i < m ; i++) a[i]=nums1[i];
        int i = 0 , j = 0 , it = 0;
        while(i<m || j<n){
            int ele1 = INT_MAX , ele2 = INT_MAX;
            if(i<m) ele1 = a[i];
            if(j<n) ele2 = nums2[j];
            
            if(ele1<ele2){
                nums1[it] = ele1;
                i++;
            }
            else{
                nums1[it] = ele2;
                j++;
            }
            it++;
        }
    }
};