/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    var joined = {}

    for (var objArray of arr1.concat(arr2)) {
        var id = objArray.id;
        joined[id] ?
        joined[id] = {...joined[id], ...objArray} :
        joined[id] = objArray
    }
    return Object.values(joined)
};