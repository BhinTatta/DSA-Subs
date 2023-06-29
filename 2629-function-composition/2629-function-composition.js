/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    var n = functions.length;
	return function(x) {
        var curr = x;
        for(var i = n-1 ; i >= 0 ; i--){
            curr = functions[i](curr);
        }
        return curr;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */