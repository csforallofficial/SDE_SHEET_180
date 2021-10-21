/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input: s = "mississippi", p = "mis*is*p*."
Output: false
 

Constraints:

1 <= s.length <= 20
1 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
*/


class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.size()+1,vector<bool>(s.size()+1,false));
        for(int i = 0; i < dp.size(); i++){
            for(int j = 0; j < dp[0].size(); j++){
                if(i == 0 && j == 0){
                    dp[i][j] = true;
                } else if(i == 0){
                    dp[i][j] = false;
                } else if(j == 0){
                    char pc = p.at(i-1);
                    if(pc == '*'){
                        dp[i][j] = dp[i-2][j];
                    } else{
                        dp[i][j] = false;
                    }
                } else{
                    char pc = p.at(i-1);
                    char sc = s.at(j-1);
                    if(pc == '*'){
                        dp[i][j] = dp[i-2][j];
                        char pslc = p.at(i-2);
                        if(pslc == '.' || pslc == sc)
                            dp[i][j] = dp[i][j] || dp[i][j-1];
                    } else if(pc == '.'){
                        dp[i][j] = dp[i-1][j-1];
                    } else if(pc == sc){
                        dp[i][j] = dp[i-1][j-1];
                    } else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[p.size()][s.size()];
    }
};
