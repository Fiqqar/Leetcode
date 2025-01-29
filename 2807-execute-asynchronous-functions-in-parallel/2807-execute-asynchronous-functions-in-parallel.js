/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
    const res = []
    let total = 0

    functions.forEach((func, index) => {
        func()
            .then((response) => {
                res[index] = response;
            })
            .catch((error) => {
                reject(error)
            })
            .finally(() => {
                total++

                if (total === functions.length) resolve(res) 
            })
    })
  })  
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */