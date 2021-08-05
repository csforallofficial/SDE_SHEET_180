#include <bits/stdc++.h>
#include <climits>
using namespace std;

int buy_sell(int arr[], int n)
{
    int min = INT_MAX, pro = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        pro = max(pro, arr[i] - min);
    }
    return pro;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = buy_sell(arr, n);
    cout << ans << endl;
}