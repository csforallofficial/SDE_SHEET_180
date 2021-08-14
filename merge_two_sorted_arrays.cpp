//1st approach- swapping & sorting

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int arr1[n],arr2[m];
    for(int i = 0; i < n; i++)
        cin >> arr1[i];
    for(int i = 0; i < m; i++)
        cin >> arr2[i];
    
    for(int i = 0; i < n; i++){
        if(arr1[i]>arr2[0])
            swap(arr1[i],arr2[0]);
        int current = arr2[0];
        int k;
        for(k=1;k<m && arr2[k]<current; k++){
            arr2[k-1]=arr2[k];
        }
        arr2[k-1]=current;
    }
    for(int i = 0; i < n; i++)
        cout << arr1[i] << " ";
    cout << endl;
    for(int i = 0; i < m; i++)
        cout << arr2[i] << " ";
    cout << endl;
    return 0;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//2nd approach - GAP method

#include<bits/stdc++.h>
using namespace std;

int NextGap(int gap){
    if(gap<=1)
        return 0;
    return (gap/2) + (gap%2);
}

int main(){
    int n,m;
    cin >> n >> m;
    int arr1[n],arr2[m];
    for(int i = 0; i < n; i++)
        cin >> arr1[i];
    for(int i = 0; i < m; i++)
        cin >> arr2[i];
    
    int gap = n+m, i, j;
    for(gap=NextGap(gap);gap>0;gap=NextGap(gap)){
        for(i = 0; i+gap < n; i++){
            if(arr1[i]>arr1[i+gap])
                swap(arr1[i],arr1[i+gap]);
        }
        for(j=gap>n?gap-n:0;i<n && j<m; i++,j++){
            if(arr1[i]>arr2[j])
                swap(arr1[i],arr2[j]);
        }
        if(j<m){
            for(j=0;j+gap<m;j++){
                if(arr2[j]>arr2[j+gap])
                    swap(arr2[j],arr2[j+gap]);
            }
        }
    }
    
    for(int i = 0; i < n; i++)
        cout << arr1[i] << " ";
    cout << endl;
    for(int i = 0; i < m; i++)
        cout << arr2[i] << " ";
    cout << endl;
    return 0;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Conversion method-

#include<bits/stdc++.h>
#include<climits>
using namespace std;

int NextGap(int gap){
    if(gap<=1)
        return 0;
    return (gap/2) + (gap%2);
}

int main(){
    int n,m;
    cin >> n >> m;
    int arr1[n],arr2[m];
    for(int i = 0; i < n; i++)
        cin >> arr1[i];
    for(int i = 0; i < m; i++)
        cin >> arr2[i];
    
    int max1=INT_MIN;
    for(int i = 0; i < n; i++)
        max1 = max(max1,arr1[i]);
    for(int i = 0; i < m; i++)
        max1 = max(max1,arr2[i]);
    max1++;
    
    int i = 0, j = 0, k = 0;
    while(i<n && j<m && k<(n+m)){
        int e1 = arr1[i]%max1;
        int e2 = arr2[j]%max1;
        if(e1<=e2){
            if(k<n){
                arr1[k]+=(e1*max1);
            }
            else{
                arr2[k-n]+=(e1*max1);
            }
            i++;
            k++;
        }
        else{
            if(k<n){
                arr1[k]+=(e2*max1);
            }
            else{
                arr2[k-n]+=(e2*max1);
            }
            j++;
            k++;
        }
    }
    while(i<n){
        int e1=arr1[i]%max1;
        if(k<n)
        {
            arr1[k]+=(e1*max1);
        }
        else{
            arr2[k-n]+=(e1*max1);
        }
        i++;
        k++;
    }
    while(j<m){
        int e2=arr2[j]%max1;
        if(k<n)
        {
            arr1[k]+=(e2*max1);
        }
        else{
            arr2[k-n]+=(e2*max1);
        }
        j++;
        k++;
    }
    for(int i = 0; i < n; i++){
        arr1[i]/=max1;
    }
    for(int i = 0; i < m; i++){
        arr2[i]/=max1;
    }
    
    for(int i = 0; i < n; i++)
        cout << arr1[i] << " ";
    cout << endl;
    for(int i = 0; i < m; i++)
        cout << arr2[i] << " ";
    cout << endl;
    return 0;
}
