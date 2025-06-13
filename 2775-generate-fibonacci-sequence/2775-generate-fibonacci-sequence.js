/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    let a1=0, a2=1;
    let next;
    while(true){
        next = a1+a2;
        yield a1;
        a1 = a2;
        a2 = next;
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */