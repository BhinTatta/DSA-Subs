/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let ans = [];
    arr.forEach((curr,index)=>{
        ans[index] = fn(curr,index);
    })
    return ans;
};