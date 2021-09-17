//1st approach - Normally assign a new array and fill it accordingly
//Time - O(N^2)
//Space - O(N^2)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int ro,co;
    cin >> ro >> co;
    int arr[ro][co];
    for(int i = 0; i < ro; i++){
        for(int j = 0; j < co; j++)
            cin >> arr[i][j];
    }
    int ans[co][ro];
    for(int i = 0; i < co; i++){
        for(int j = 0; j < ro; j++){
            ans[i][j] = arr[ro-j-1][i];
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

---------------------------------------------------------------------------------------------------------------------------------------------------------------------

//2nd approach - Transpose the array and reverse every row
//Time - O(N^2) 
//Space - O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(int i = 0; i < n; i++)
            reverse(matrix[i].begin(),matrix[i].end());
    }
};
