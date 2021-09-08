/*
*/

//1st approach - Iterate through every array element and place them in a hashset. The hashset will store unique elements in it in ascending order.
//Then place all the elements from the hashset into the original array in ascending order
//Time - O(NlogN) + O(N), NlogN for inserting unique elements into the hashset, and N for placing back the unique elements into the original array.
//Space - O(N) for the hashset

//2nd approach - Take two pointers 'i' and 'j'. Keep 'i' at 0 and 'j' at 1. Iterate till 'j' reaches array end. Check if element[i] = element[j]. 
//If yes, do nothing. If not same, move 'i' pointer forward by 1 and initialize element[i] = element[j].
//finally return 'i+1'
//Time - O(N)
//Space - O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int i = 0, j = 1;
        while(j<nums.size()){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
        return i+1;
    }
};
