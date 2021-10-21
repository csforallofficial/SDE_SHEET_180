/* 
INPUT - [4,2,2,6,4], XOR = 6
OUTPUT - 3
*/


#include <bits/stdc++.h>
#include<map>
using namespace std;

int main() {
	int n,k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++)
	    cin >> arr[i];
	unordered_map<int,int> mp;
	int xo = 0, len = 0;
	for(int i = 0; i < n; i++){
	    xo ^= arr[i];
	    if(mp.find(xo^k)!=mp.end())
            len = max(len,i-mp[xo^k]);
        else{
            if(mp.find(xo)==mp.end())
	            mp[xo] = i;
        }
	}
	
	cout << len << endl;
	return 0;
}

