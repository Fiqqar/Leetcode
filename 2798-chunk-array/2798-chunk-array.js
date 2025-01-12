/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    var arrayChunk = [];

    var i = 0;

    while(i <  arr.length) {
        arrayChunk.push(arr.slice(i, i + size));
        i += size;
    }
    return arrayChunk;
};
