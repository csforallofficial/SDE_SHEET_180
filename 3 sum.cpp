/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

//1st approach - Run 3 loops to take into account all the triplets which sum up to be zero. If the triplets match the criteria, insert them into a set to find only the unique triplets.
//Time - O(N^3 * log M), N^3 for running 3 for loops and log M for inserting the triplets into the set.
//Space - O(M), for M triplets need to inserted into the set

//2nd approach - Create a hash map containing the number of occurence of the elements in the array.
//Run 2 loops to consider 2 elements at a time. for example an 'i' and a 'j' loop. For every 'i' loop, decrease the no. of occurence of 'i' element in the hash map.
//For every 'j' loop, decrease the no. of occurence of 'j' element in the hash map. Element at 'i' be 'a' and element at 'j' be 'b'. 
//Now check if '-(a+b)' is present in the hash map. If yes, insert the triplet into a set.
//After this again increase the occurence of 'i' element and 'j' element in the hash map. 
//Time - O(N^2 * log M), N^2 for two loops and log M for inserting the M unique triplets.
//Space - O(N) + O(M), O(N) for the hash map and O(M) for the set containing M unique triplets

//3rd approach - Two pointer approach. If we consider a+b+c = 0, then b+c = -a. So we just need to find 'b+c' pair, which gives us '-a'.
//we sort the array
//We traverse through the array as 'a'. 'b' is signified by a 'lo' = ('a' + 1)th element, and 'c' is signified by a 'hi' = last element of the array.
//We sum up 'lo' nd 'hi' and check if they give us '-a'. If yes, we push the triplet into the vector, else if the sum is less than '-a', we move 'lo' pointer towards right,
//if the sum is more than '-a', we move 'hi' pointer towards left. 
//if triplet found, we don't consider the same elements for any further triplets any more. We move a,b,c to numbers not equal to thier previous values.
//Time - O(N^2) 
//Space - O(1) - auxillary space, O(M) if size of vector is considered.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res; 
        if((int)(nums.size())<3)
            return res;
        sort(nums.begin(), nums.end()); 
        
        // moves for a
        for (int i = 0; i < (int)(nums.size())-2 && nums[i] <= 0; i++) {
            
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                
                int lo = i+1, hi = (int)(nums.size())-1, sum = 0 - nums[i];
                
                while (lo < hi) {
                    if (nums[lo] + nums[hi] == sum) {
                        
                        vector<int> temp; 
                        temp.push_back(nums[i]); 
                        temp.push_back(nums[lo]); 
                        temp.push_back(nums[hi]); 
                        res.push_back(temp);
                        
                        while (lo < hi && nums[lo] == nums[lo+1]) lo++;
                        while (lo < hi && nums[hi] == nums[hi-1]) hi--;
                        
                        lo++; hi--;
                    } 
                    else if (nums[lo] + nums[hi] < sum) lo++;
                    else hi--;
               }
            }
        }
        return res;
    }
};
