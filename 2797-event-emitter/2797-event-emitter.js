class EventEmitter {
    constructor() {
        this.events = new Map();
    }
    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    subscribe(eventName, callback) {
        if(!this.events.has(eventName)) {
            this.events.set(eventName, [])
        }
        const listeners = this.events.get(eventName);
        listeners.push(callback)
        return {
            unsubscribe: () => {
                const i = listeners.indexOf(callback);
                if (i !== -1) {
                    listeners.splice(i, 1)
                }
            }
        };
    }
    
    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
        if (!this.events.has(eventName)) {
            return []
        }

        const listeners = this.events.get(eventName);
        const res = []

        for (const listener of listeners) {
            res.push(listener(...args))
        }
        return res
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */