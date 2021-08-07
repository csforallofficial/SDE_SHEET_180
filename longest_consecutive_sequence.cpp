/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashSet;
        for(int num:nums){
            hashSet.insert(num);
        }
        int longest_streak = 0;
        for(int num:nums){
            if(!hashSet.count(num-1)){
                int currentnum = num;
                int current_streak = 1;
                
                while(hashSet.count(currentnum+1)){
                    currentnum +=1;
                    current_streak +=1;
                }
                longest_streak = max(longest_streak,current_streak);
            }
        }
        return longest_streak;
    }
};
