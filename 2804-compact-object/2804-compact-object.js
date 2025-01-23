/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if(Array.isArray(obj)) {
        return obj.filter(Boolean).map(compactObject);
    } else if (obj !== null && typeof obj === "object") {
        let dummy = {};
        for (let prop in obj) {
            let value = compactObject(obj[prop]);
            if (Boolean(value) || typeof value === "object") {
                if (value !== null) dummy[prop] = value
            }
        }
        return dummy;
    }
    return obj;
};