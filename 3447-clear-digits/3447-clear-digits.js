/**
 * @param {string} s
 * @return {string}
 */
var clearDigits = function(s) {
    const otp = [];
    const num = '01234567890'
    
    for(const char of s){
        if(num.indexOf(char) !== -1){
            otp.pop();
        }else{
            otp.push(char)
        }
    }
    
    return otp.join("");
};