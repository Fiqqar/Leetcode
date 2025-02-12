/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let obj={'(':')','{':'}','[':']'}
    let stk=[]
    for(let char of s){
        if(obj[char]) stk.push(char)
        else if(obj[stk.pop()]!==char) return false
    }
    return stk.length==0
};