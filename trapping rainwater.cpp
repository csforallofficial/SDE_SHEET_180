/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9.
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

//1st approach - For every index, consider the maximum hieght on the left and maximum height on the right, and find the minumum between them. Then do (min - element[i]).
//we will get the amount of water that can be stored in that index. Calculate for every element and return the sum.
//Time - O(N^2)
//Space - O(1)

//2nd approach - Make a prefix sum array and a suffix sum array storing the max heights till every index. Then do min(prefix[i],suffix element[i]) - element[i]
//we will get the amount of water that can be stored in that index. Calculate for every element and return the sum.
//Time - O(N)
//Space - O(N)

//3rd approach - We take two pointers 'left' and 'right'. We keep track of 2 variables, 'leftmax' and 'rightmax' which stores the maximum from left till the 'left' pointer and 
//maximum from right till the 'right' pointer. If height at 'left' pointer is less than equal to height at 'right' pointer, i can surely say i can store water in between 'left'
//and 'right' pointer and vice versa. If (height[left] <= height[right]), I will check if element at left is less than equal to 'leftmax', if yes, resultant += leftmax - height[left].
//else, 'leftmax' = height[left].
//If (height[left] > height[right]), I will check if element at right is less than equal to 'rightmax', if yes, resultant += rightmax - height[right]. else, 'rightmax' = height[right].
//Finally return resultant.
//Time - O(N)
//Space - O(1)


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int maxleft = 0, maxright = 0, res = 0;
        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] >= maxleft)
                    maxleft = height[left];
                else
                    res += maxleft - height[left];
                left++;
            }
            else{
                if(height[right] >= maxright)
                    maxright = height[right];
                else
                    res += maxright - height[right];
                right--;
            }
        }
        return res;
    }
};
