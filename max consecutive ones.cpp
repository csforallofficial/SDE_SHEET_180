/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/

//optimal approach - Iterate through every element of the array. If it's 1, increase value of count by 1 which was initially assigned to 0. If it's 0, assign count to 0.
//After each iteration, compare count with the maximum, if count>maximum, maximum = count. After all iteration, return maximum.
//Time - O(N)
//Space - O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        if(nums.size() == 1 && nums[0] == 1)
            return count+1;
        if(nums.size() == 1 && nums[0] == 0)
            return count;
        int max1 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1)
                count++;
            else
                count = 0;
            if(count > max1)
                max1 = count;
        }
        return max1;
    }
};
