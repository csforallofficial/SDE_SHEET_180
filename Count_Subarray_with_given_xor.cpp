/*
Given an array of integers arr[] and a number m, count the number of subarrays having XOR of their elements as m.
Examples: 

Input : arr[] = {4, 2, 2, 6, 4}, m = 6
Output : 4
Explanation : The subarrays having XOR of 
              their elements as 6 are {4, 2}, 
              {4, 2, 2, 6, 4}, {2, 2, 6},
               and {6}

Input : arr[] = {5, 6, 7, 8, 9}, m = 5
Output : 2
Explanation : The subarrays having XOR of
              their elements as 5 are {5}
              and {5, 6, 7, 8, 9}
*/


int Solution::solve(vector<int> &A, int B){
    map<int, int> mp;
    int xorr = 0, count = 0;
    for(auto it:A){
        xorr = xorr ^ it;
        if(xorr == B)
            count++;
        if(mp.find(xorr^B) != mp.end())
            cnt += mp[xorr^B];
        mp[xorr] += 1;
    }
    return count;
}
