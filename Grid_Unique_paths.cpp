/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
Example 3:

Input: m = 7, n = 3
Output: 28
Example 4:

Input: m = 3, n = 3
Output: 6
 

Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 109.
*/


//Most Optimal Code

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n+m-2, r = m-1;
        double ans = 1;
        for(int i = 1; i <= r; i++){
            ans = ans*(N-r+i)/i;
        }
        return int(ans);
    }
};


//Recursion Solution

class Solution {
public:
    int uniquePaths(int i, int j, int n, int m) {
        if(i>=n | j>=m)
            return 0;
        if(i == n-1 && j == m-1)
            return 1;
        return uniquePaths(i+1,j) + uniquePaths(i,j+1);
    }
};


//Dynamic Programming Solution

class Solution {
public:
    int uniquePaths(int i, int j, vector<vector<int>> &dp, int n, int m) {
        if(i>=n | j>=m)
            return 0;
        if(i == n-1 && j == m-1)
            return 1;
        if (dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j] = uniquePaths(i+1,j,dp) + uniquePaths(i,j+1,dp);
    }
};
