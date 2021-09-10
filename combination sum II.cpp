/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/


//Brute approach - same as combination sum I, only change would have been, whether you pick element from an index or not, you have to do func(ind+1). And finally, store 
//the combinations in a set to avoid duplicates.
//Time - O(2^T * KlogK), T is the target and KlogK because of inserting the combinations in a set, K size of the data structure which will contain each combinations. 
//Space - O(k * X), where K is the size of each possible combination and X is the number of combinations.

//Optimal approach - First we sort the input. After sorting Input = [1,1,1,2,2]. So first recursive call will start from the 0th index --> func(0,4,[]) --> 4 is target.
//Now we have total 5 options or index to pick our next combination from (0,1,2,3,4). We can choose 0th index(1), 1st index(1), 2nd index(1), 3rd index(2), 4th index(2)
//For this we can run a loop starting from ind to n-1. But we should make sure that, if we choose '1' from any of the 0th,1st or 2nd index, we can't choose another '1'
//from any other index here. //So my first node will have a combination length 1. In the second node, we have combinations (1,3,[1]) and (4,2,[2]).
//For (1,[1]) we have options 1st index(1), 2nd index(1), 3rd index(2), 4th index(2). No if we choose 1st index(1), we can't choose 2nd index(1) in the adjacent 
//combination. Similarly if we choose 3rd index(2), we can't choose 4th index(2) in the adjacent combination. Every number should be unique in each node level.
//If my target becomes zero, i can get assured that i got a valid combination, and push that into my answer. If at any point i find, my number is greater than taget
//i break the recursion.
//Time - O(2^N * K), K is the average length of each combinations
//Space - O(K * X), K --> average length of each combination and X --> number of combinations.


class Solution {
    public:
    void func(int ind,int target, vector<int> &candidates, vector<int> &ds, vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i = ind; i < candidates.size(); i++){
            if(i!=ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            func(i+1, target - candidates[i], candidates, ds, ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        func(0,target,candidates,ds,ans);
        return ans;
    }
};
