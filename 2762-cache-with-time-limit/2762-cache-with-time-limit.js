var TimeLimitedCache = function() {
    this.store = new Map();
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    const exist = this.store.has(key);
    if (exist) {
        clearTimeout(this.store.get(key).timer);
    }
    this.store.set(key, {
        value,
        timer: setTimeout(() => this.store.delete(key), duration)
    });
    return exist;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    const exists = this.store.has(key);
    if (exists) {
        return this.store.get(key).value;
    }
    return -1;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    return this.store.size;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */