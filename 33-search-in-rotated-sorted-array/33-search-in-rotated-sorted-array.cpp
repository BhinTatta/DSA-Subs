class Solution {
public:
    int search(vector<int>& nums, int target) {
          int low = 0, high = nums.size() - 1; //<---step 1

  while (low <= high) { //<--- step 2
    int mid = (low + high) >> 1; //<----step 3
    if (nums[mid] == target)
      return mid; // <---step 4

    if (nums[low] <= nums[mid]) { //<---step 5
      if (nums[low] <= target && nums[mid] >= target)
        high = mid - 1; //<---step 6 
      else
        low = mid + 1; //<---step 7
    } else { //<---step 7
      if (nums[mid] <= target && target <= nums[high])
        low = mid + 1;
      else
        high = mid - 1;
    }
  }
  return -1;
//         int n = nums.size();
//         int l = 0 , r = n-1;
        
//         while(l<=r){
//             int mid = (r+l)/2;
            
//             int lval = nums[l] , midval = nums[mid] , rval = nums[r];
            
//             if(k = midval) return mid;
//             //left is sorted
//             if(lval<=midval){
//                 if( lval<= k && k <= midval ) r = mid-1;
//                 else l = mid+1;
//             }
//             else{
//                 if(midval<=k && k<=rval) l = mid+1;
//                 else r = mid-1;
//             }
//         }
//         return -1;
    }
};