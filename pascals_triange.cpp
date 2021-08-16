#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >>n;
	vector<vector<int>> vec(n);
	for(int i = 0; i < n; i++){
	    vec[i].resize(i+1);
	    vec[i][0]=vec[i][i] = 1;
	    for(int j = 1; j < i; j++){
	        vec[i][j] = vec[i-1][j-1] + vec[i-1][j];
	    }
	}
	for(int i = 0; i < vec.size(); i++){
	    for(int j = 0; j < vec[i].size(); j++){
	        cout << vec[i][j] << " ";
	    }
	    cout << endl;
	}
	return 0;
}
