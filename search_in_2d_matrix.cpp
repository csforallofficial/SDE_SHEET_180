/* Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104 */


//1st approach - start from the top right and traverse accordingly
//Time - O(N^2)
//Space - O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0, j = m-1;
        while(i < n && j >= 0){
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] < target)
                i++;
            else
                j--;
        }
        return false;
    }
};


--------------------------------------------------------------------------------------------------------------------------------------------

//2nd approach - Using modules
//Time - O(N)
//Space - O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)
            return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int lo = 0, hi = (n*m-1);
        while(lo<=hi){
            int mid = (lo + (hi-lo)/2);
            if(matrix[mid/m][mid%m] == target)
                return true;
            else if(matrix[mid/m][mid%m] < target){
                lo = mid+1;   
            }
            else
                hi = mid-1;
        }
        return false;
    }
};
