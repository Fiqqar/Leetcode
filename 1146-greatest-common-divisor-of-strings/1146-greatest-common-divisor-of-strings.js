/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function(str1, str2) {
    if (str1 + str2 != str2 + str1) return ''
    let m = str1.length
    let n = str2.length

    let divs = function (x, y) {
        if (!y) return x
        return divs(y, x % y)
    }

    let div = divs (m, n)
    return str1.slice(0, div)
};