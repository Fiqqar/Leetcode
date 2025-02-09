/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    let kiri = 0;
    let kanan = x;
    while(kiri <= kanan) {
        const mid = Math.floor((kiri+kanan)/2);
        if(mid*mid <= x && (mid+1) * (mid+1) > x) {
            return mid;
        }
        else if(mid*mid < x) {
            kiri = mid + 1;
        }
        else {
            kanan = mid - 1;
        }
    }
};