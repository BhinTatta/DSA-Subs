/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    var val = init;
    if(nums.length == 0) return init;
    
    
    nums.forEach( (ele , i) => {
        val = fn(val,ele);
    } )

    return val;
};