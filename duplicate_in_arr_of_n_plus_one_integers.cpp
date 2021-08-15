//1st approach - O(n^2)

#include<bits/stdc++.h>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int count, max1=0, cur_ele;
    for(int i = 0; i < n; i++){
        count = 0;
        for(int j = i+1; j < n; j++){
            if(arr[i]==arr[j])
                count++;
            if(count>max1){
                max1 = count;
                cur_ele = i;
            }
        }
    }
    cout << arr[cur_ele] << endl;
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//2nd approach - O(nlogn)

#include<bits/stdc++.h>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr,arr+n);
    int i = 0;
    for(i = 0; i < n-1; i++){
        if(arr[i]==arr[i+1])
            break;
    }
    cout << arr[i] << endl;
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//3rd approach - Time -->O(n)       Space --> O(n)

#include<bits/stdc++.h>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int temp[n]={0};
    for(int i = 0; i < n; i++)
        temp[arr[i]]++;
    int i = 0;
    for(i = 0; i < n; i++){
        if(temp[i]>1)   
            break;
    }
    cout << i << endl;
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//4th approach - Time -->O(n)       Space --> O(1)

#include<bits/stdc++.h>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int fast = arr[0], slow = arr[0];
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow!=fast);
    
    fast = arr[0];
    while(slow!=fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    cout << slow << endl;
    return 0;
}
