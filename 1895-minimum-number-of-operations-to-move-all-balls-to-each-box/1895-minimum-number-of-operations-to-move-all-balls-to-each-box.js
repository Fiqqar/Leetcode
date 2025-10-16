/**
 * @param {string} boxes
 * @return {number[]}
 */
const minOperations = boxes => {
    const indexes = []
    
    for (const i in boxes) {
        if (boxes[i] === '1') indexes.push(i)
    }
    
    const answer = []
    
    for (const i in boxes) {
        let moves = 0
        
        for (const index of indexes) {
            moves += Math.abs(i - index)
        }
        
        answer.push(moves)
    }
    
    return answer
}