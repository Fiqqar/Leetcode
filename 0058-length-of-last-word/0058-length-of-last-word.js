/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    const array = s.trim().split(' ');
    return array[array.length-1].toString().length;
};