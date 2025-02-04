/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    let res = 0;
    
    for (let i = 0; i < s.length; i++) {
        const current = s[i];
        const next = s[i + 1];
        
        if (current === 'M') res += 1000;
        else if (current === 'D') res += 500;
        else if (current === 'C') {
            if (next === 'M') { res += 900; i++; }
            else if (next === 'D') { res += 400; i++; }
            else res += 100;
        }
        else if (current === 'L') res += 50;
        else if (current === 'X') {
            if (next === 'C') { res += 90; i++; }
            else if (next === 'L') { res += 40; i++; }
            else res += 10;
        }
        else if (current === 'V') res += 5;
        else if (current === 'I') {
            if (next === 'X') { res += 9; i++; }
            else if (next === 'V') { res += 4; i++; }
            else res += 1;
        }
    }
    
    return res;
};