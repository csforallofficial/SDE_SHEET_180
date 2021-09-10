/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

//approach - Recursive tree method. If i have an input [1,3,2,3,2,3], first sort it --> [1,2,2,3,3,3]. Then i will first start with a recursive call at '0' index and a data structure(list here) of size 0.
//That is my root node would be [0,0'] where 0 is the index and 0' is the number in the list i.e, NULL. Then in the next node, i can take a list of size 1. So my 
//possible numbers can be 1(index = 0) or 2(index  =1,2) or 3(index = 3,4,5). Since i'm not allowed to take duplicates, I can take only 1(index = 0) and 2(index = 1) 
//and 3(index = 3). So my nodes are [1,1], [2,2], [4,3]. So this node contains all lists of size 1. In the next node i will have lists of size 2.
//So for [1,1] i will have two options --> [2,(1,2)] and [4,(1,3)]. Similarly for [2,2], i will have [3,(2,2)] and [4,(2,3)]. I (2,2) won't be considered duplicate
//because it's the first occurence, if i had another (2,2) instead of (2,3), then it would have been considered duplicate. So the process wil continue now.
//Time - O(2^N * N), 2^N for the number of subsets and N is the average length of subset.
//Space - O(2^N * N), 2^N space for 2^N number of subsets and N depicts the average of subsets.
//Auxilliary space of recursive call - O(N)


class Solution {
    public:
    void func(int ind, vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int i = ind; i < nums.size(); i++){
            if(i!=ind && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            func(i+1,ds,nums,ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> ds;
        func(0,ds,nums,ans);
        return ans;
    }
};
