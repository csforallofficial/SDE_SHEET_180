#include<bits/stdc++.h>
#include<vector>
using namespace std;

int merge(int arr[], int low, int mid, int high){
    int j = mid+1, count = 0;
    for(int i = low; i <= mid; i++){
        while(j<=high && arr[i] > arr[j])
            j++;
        count += j - (mid+1);
    }
    
    int left = low, right = mid+1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }
    while(left<=mid)
        temp.push_back(arr[left++]);
    while(right<=high)
        temp.push_back(arr[right++]);
    for(int i = low; i <= high; i++)
        arr[i] = temp[i-low];
    return count;
}

int inv_count(int arr[], int low, int high){
    if(low>=high)
        return 0;
    int mid = (low+high)/2;
    int count = inv_count(arr,low,mid);
    count += inv_count(arr,mid+1,high);
    count += merge(arr,low,mid,high);
    return count;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = inv_count(arr,0,n-1);
    cout << ans << endl;
    return 0;
}
