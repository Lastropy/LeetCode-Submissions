/**
 * @param {Function} fn
 */
function memoize(fn) {
    let cache = {};
    return function(...args) {
        if(fn in cache){
            if(!(args in cache[fn]))
                cache[fn][args] = fn(...args);
            return cache[fn][args];
        }
        else{
            cache[fn] = {};
            cache[fn][args] = fn(...args);
            return cache[fn][args];
        }
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */