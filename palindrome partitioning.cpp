/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/


//optimal approach - If a string "aabb" is given, my idea would be start from the first index and check if a partition would be give me a palindrome string. If yes,
//i will do the partition and move to downward node. Similarly i would check for possible partitions at all other indexex, if they are valid, i will consider them,
//and move to the downward node. If my partitioning index reach the string end, then i would be assured that the modified string is valid and i would push it into
//my answer and return it.

class Solution {
    public:
    void func(int ind, string s, vector<vector<string>> &ans, vector<string> &path){
        if(ind == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i = ind; i < s.size(); ++i){
            if(isPalindrome(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                func(i+1,s,ans,path);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        func(0,s,ans,path);
        return ans;
    }
};
