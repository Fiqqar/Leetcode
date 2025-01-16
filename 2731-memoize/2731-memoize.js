/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const cace = {};
    return function(...args) {
        const ket = JSON.stringify(args);
        if (ket in cace) {
            return cace[ket];
        }
        cace[ket] = fn(...args);
        return cace[ket]
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