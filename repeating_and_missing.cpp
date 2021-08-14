#include <bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> MissingAnd_Repeating(vector<int> arr){
    int xor1=arr[0],set_bit_no, c1=0, c2=0, n = arr.size();
    vector<int> res;
    int* x=(int*)malloc(sizeof(int));
    int* y=(int*)malloc(sizeof(int));
    for(int i = 1; i < n; i++)
        xor1^=arr[i];
    for(int i = 1; i <= n; i++)
        xor1^=i;
    set_bit_no = xor1 & ~(xor1-1);
    for(int i = 0; i < n; i++){
        if(set_bit_no & arr[i])
            *x = *x^arr[i];
        else
            *y = *y^arr[i];
    }
    for(int i = 1; i <= n; i++){
        if(set_bit_no & i)
            *x = *x^i;
        else
            *y = *y^i;
    }
    for(int i = 0; i < n; i++){
        if(arr[i]==*x)
            c1++;
        else
            c2++;
    }
    res.push_back(*x);
    res.push_back(*y);
    return res;
}

int main() {
    int n;
    cin >> n;
	vector<int> arr;
	int input;
	for(int i = 0; i < n; i++){
	    cin >> input;
	    arr.push_back(input);
	}
	vector<int> ans;
	ans=MissingAnd_Repeating(arr);
	for(int i = 0; i < 2; i++)
	    cout << ans[i] << " ";
    cout << endl;
	return 0;
}
