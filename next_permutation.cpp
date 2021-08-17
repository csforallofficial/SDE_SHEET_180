#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
	    cin >> arr[i];
	}
	int i;
	bool flag = false;
	for(i = n-2; i >= 0; i--){
	    if(arr[i+1]>arr[i]){
	        flag = true;
	        break;  
	    }
	}
	if(flag == false){
	    reverse(arr,arr+n);
	}
	else{
	    int j;
	    for(j = n-1; j > i; j--){
	        if(arr[j]>arr[i])
	            break;
	    }
	    swap(arr[i],arr[j]);
	    reverse(arr+i+1,arr+n);
	}
	for(int i = 0; i < n; i++)
	    cout << arr[i] << " ";
    cout << endl;
	return 0;
}
