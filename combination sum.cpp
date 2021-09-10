/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
Example 4:

Input: candidates = [1], target = 1
Output: [[1]]
Example 5:

Input: candidates = [1], target = 2
Output: [[1,1]]
 

Constraints:

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
All elements of candidates are distinct.
1 <= target <= 500
*/


//optimal approach - Recursive tree method - Suppose my input is [2,3,6,7] and target is 7. So i start with recursion call at 0th index --> func(0,7,[]), where 0 is index
//7 is target, and [] is my data structure where i will store each combination. So now i have two options, I can pick the 0th index and i can not pick the 0th index.
//If i pick, i will stay a 0th index and my target will reduce by the number at 0th index. So it will give me a node func(0,5,[2]). And if i not pick the 0th index,
//I will move to the 1st index and my target will remain same. So it will give me another node func(1,7,[]). Similarly i will have two node options for func(0,5,[2])
//and 2 node options for func(1,7,[]). In this way the recursive tree will grow. When i reach index = N and target = 0, I know i have got a possible combination.
//I will push that into the answer vector, and if i reach index = N and target != 0, that's not a valid combination and my recursive tree will backtrack to a possible
//node from where i can again get a valid combination.
//Time - O(2^T * K), where T is the target sum an K is the size of data structure which will contain each possible combination.
//Space - O(K * X), where K is the size of each possible combination and X is the number of combinations.


class Solution {
    public:
    void func(int ind, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds){
        if(ind == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[ind] <= target){
            ds.push_back(candidates[ind]);
            func(ind,target-candidates[ind],candidates,ans,ds);
            ds.pop_back();
        }
        func(ind+1,target,candidates,ans,ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        func(0,target,candidates,ans,ds);
        return ans;
    }
};
