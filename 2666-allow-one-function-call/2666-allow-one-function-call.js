/**
 * @param {Function} fn
 * @return {Function}
 */
let called = new Set();
var once = function(fn) {
    return function(...args){
        if(!called.has(fn)){
            called.add(fn)
            return fn(...args);
        }
        return undefined;
    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
