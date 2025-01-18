/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    const hasil = {};

    for (let i = 0; i < this.length; i++) {
        const key = fn(this[i]);
        
        if (!hasil[key]) {
            hasil[key] = [];
        }
        
        hasil[key].push(this[i]);
    }

    return hasil;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */