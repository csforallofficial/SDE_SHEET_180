/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.empty())
            return res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int new_target = target - nums[i] - nums[j];
                int front = j+1;
                int back = n-1;
                while(front<back){
                    if(nums[front]+nums[back] < new_target)
                        front++;
                    else if(nums[front]+nums[back] > new_target)
                        back--;
                    else{
                        vector<int> quad(4,0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[front];
                        quad[3] = nums[back];
                        res.push_back(quad);
                        
                        while(front<back && nums[front]==quad[2])
                            ++front;
                        while(front<back && nums[back]==quad[3])
                            --back;
                    }
                }
                while(j+1<n && nums[j+1]==nums[j])
                    ++j;
            }
            while(i+1<n && nums[i+1]==nums[i])
                ++i;
        }
        return res;
    }
};
