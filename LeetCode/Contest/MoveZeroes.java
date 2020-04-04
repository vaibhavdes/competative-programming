
/*

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

*/

class Solution {
    public void moveZeroes(int[] nums) {
        if(nums.length ==0)
            return;
        int position = 0;
        for(int number : nums){
            if(number != 0)
                nums[position++] = number;
        }
        while(position < nums.length)
            nums[position++] = 0;
    }
}
