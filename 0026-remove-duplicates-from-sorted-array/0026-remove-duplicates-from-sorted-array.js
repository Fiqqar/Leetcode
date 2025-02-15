/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let j=-1;
        for(let i=0;i<nums.length;i++){
            if(nums[i]==nums[i+1]){
            } 
            else{
                j++;
                nums[j]=nums[i];
            }
        }
    return j+1;
};