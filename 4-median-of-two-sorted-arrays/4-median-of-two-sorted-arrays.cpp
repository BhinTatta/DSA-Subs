class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {       
        if(nums2.size()  < nums1.size()){
            return findMedianSortedArrays(nums2, nums1);
        }   
        
        int n = nums1.size();
        int m = nums2.size();   
        
        double ans = 0;

        int l = 0 , r = n;

        while(l<=r){
            
            int cut1 = (l+r)>>1;
            int cut2 = (n+m+1)/2 - cut1;
            
            int l1 = cut1==0 ? INT_MIN : nums1[cut1-1];
            int l2 = cut2==0 ? INT_MIN : nums2[cut2-1];
            
            int r1 = cut1==n ? INT_MAX : nums1[cut1];
            int r2 = cut2==m ? INT_MAX : nums2[cut2];
            
            if(l1<=r2 && l2<=r1){
                //cout<<"hehe";
                if((n+m)%2){
                    return ans = max(l1,l2);
                }
                else{
                    return ans = ( max(l1,l2) + min(r1,r2) ) / 2.0;
                }
            }
            else if(l1>r2) r = cut1-1;
            else l = cut1+1;     
        }
        
        
        return 1;
    }
};















