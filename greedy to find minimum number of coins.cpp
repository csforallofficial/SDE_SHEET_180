/*
Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change?

Examples:  

Input: V = 70
Output: 2
We need a 50 Rs note and a 20 Rs note.

Input: V = 121
Output: 3
We need a 100 Rs note, a 20 Rs note and a 1 Rs coin.
*/

//Time - O(V) , V is the coin input
//Space - O(V) for vector storing at worst V coins


#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    int arr[9] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int v;
    cin >> v;
    vector<int> res;
    for(int i = 8; i >= 0; i--){
        while(v >= arr[i]){
            v -= arr[i];
            res.push_back(arr[i]);
        }
    }
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}
