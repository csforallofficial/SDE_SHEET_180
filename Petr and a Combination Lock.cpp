/*
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Petr has just bought a new car. He's just arrived at the most known Petersburg's petrol station to refuel it when he suddenly discovered that the petrol tank is secured with a combination lock! The lock has a scale of 360 degrees and a pointer which initially points at zero:


Petr called his car dealer, who instructed him to rotate the lock's wheel exactly n times. The i-th rotation should be ai degrees, either clockwise or counterclockwise, and after all n rotations the pointer should again point at zero.

This confused Petr a little bit as he isn't sure which rotations should be done clockwise and which should be done counterclockwise. As there are many possible ways of rotating the lock, help him and find out whether there exists at least one, such that after all n rotations the pointer will point at zero again.

Input
The first line contains one integer n (1≤n≤15) — the number of rotations.

Each of the following n lines contains one integer ai (1≤ai≤180) — the angle of the i-th rotation in degrees.

Output
If it is possible to do all the rotations so that the pointer will point at zero after all of them are performed, print a single word "YES". Otherwise, print "NO". Petr will probably buy a new car in this case.

You can print each letter in any case (upper or lower).

Examples
inputCopy
3
10
20
30
outputCopy
YES
inputCopy
3
10
10
10
outputCopy
NO
inputCopy
3
120
120
120
outputCopy
YES
Note
In the first example, we can achieve our goal by applying the first and the second rotation clockwise, and performing the third rotation counterclockwise.

In the second example, it's impossible to perform the rotations in order to make the pointer point at zero in the end.

In the third example, Petr can do all three rotations clockwise. In this case, the whole wheel will be rotated by 360 degrees clockwise and the pointer will point at zero again.
*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int sum = 0;
    bool flag = false;
    for(int num = 0; num < (1<<n); num++){
        for(int i = 0; i < n; i++){
            if(num & (1<<i))
                sum += arr[i];
            else
                sum -= arr[i];
        }
        if(sum == 0 || sum == 360){
            flag = true;
            break;
        }
        sum = 0;
    }
    if(flag == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
