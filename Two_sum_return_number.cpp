#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int target;
	cin >> target;
	int arr[n];
	for(int i = 0; i < n; i++){
	    cin >> arr[i];
	}
	
	unordered_set<int> us;
	for(int i = 0; i < n; i++){
	    if(us.find(target-arr[i])!=us.end())
	        cout << arr[i] << " " << target-arr[i] << endl;
	    else
	        us.insert(arr[i]);
	}
	return 0;
}
