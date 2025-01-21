/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    let result = [];
    arr.forEach((ar) => {
        if(Array.isArray(ar) && n>0){
            result.push(...flat(ar,n-1));
        }
        else{
            result.push(ar);
        }
    })

    return result;
};