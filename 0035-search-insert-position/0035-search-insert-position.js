/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    var arr = nums.length
    for (let i = 0; i < arr; i++) {
        var num = nums[i]
        if (target == num || target < num) return i;
    }
    return arr
};