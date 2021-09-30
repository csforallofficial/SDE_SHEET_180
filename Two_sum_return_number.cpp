//1st approach - Check for every element given if it's supplementary element is present.
//Time - O(N^2)
//Space - O(1)

#include<iostream>
#include<algorithm> 
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int sum;
    cin >> sum;
    vector<int> ans;
    for(int i = 0; i < n - 1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] + arr[j] == sum){
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
            }
        }
    }
    for(auto it:ans)
        cout << it << " ";
    cout << endl;
    return 0;
}

//2nd approach - Sort the elements. For every element do a binary search for it's supplementary as long as (the element <= sum/2). 
//Time - O(NlogN)
//Space - O(1)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    int input;
    for(int i = 0; i < n; i++){
        cin >> input;
        arr.push_back(input);
    }
    int sum;
    cin >> sum;
    sort(arr.begin(),arr.end());
    vector<int> ans;
    int i = 0;
    while(arr[i] <= sum/2){
        if(binary_search(arr.begin()+i+1,arr.end(),sum-arr[i])){
            ans.push_back(arr[i]);
            ans.push_back(sum-arr[i]);
        }
        i++;
    }
    for(auto it:ans)
        cout << it << " ";
    cout << endl;
    return 0;
}

//3rd approach - 


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
