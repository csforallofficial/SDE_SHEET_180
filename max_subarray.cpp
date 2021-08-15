//1st approach-
#include<bits/stdc++.h>
#include<climits>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int max1=INT_MIN, sum;
    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = i; j < n; j++){
            sum+= arr[j];
            max1 = max(max1,sum);
        }
    }
    cout << max1;
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//2nd approach-
#include<bits/stdc++.h>
#include<climits>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int max1=INT_MIN, cur_sum=0;
    for(int i = 0; i < n; i++){
        cur_sum+=arr[i];
        if(cur_sum<0)
            cur_sum=0;
        else
            max1=max(max1,sum);
    }
    cout << max1;
    return 0;
}
