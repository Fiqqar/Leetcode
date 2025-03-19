/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    let stp1 = 1;
    let stp2 = 1;

    for (let i = 0; i< n; i++) {
        let atmpt = stp1
        stp1 = stp1 + stp2
        stp2 = atmpt
    }
    return stp2
};