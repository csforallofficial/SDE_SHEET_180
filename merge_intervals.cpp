//1st approach - O(n^2) --> n = number of rows

#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals){
    vector<vector<int>> merged_intervals;
    if(intervals.size()==0)
        return merged_intervals;
    sort(intervals.begin(),intervals.end());
    vector<int> temp_interval;
    int ro = intervals.size();
    for(int i = 0; i < ro; i++){
        temp_interval = intervals[i];
        for(int j = i+1; j < ro; j++){
            if(intervals[j][0]<temp_interval[1]){
                temp_interval[1]=max(temp_interval[1],intervals[j][1]);
                i+=j;
            }
        }
        merged_intervals.push_back(temp_interval);
    }
    return merged_intervals;
}
int main(){
    int ro,co,input;
    cin >> ro >> co;
    vector<vector<int>> vec(ro);
    for(int i = 0; i < ro; i++){
        vec[i]=vector<int>(co);
        for(int j = 0; j < co; j++){
            cin >> vec[i][j];
        }
    }
    vector<vector<int>> res;
    res = merge(vec);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//2nd approach- O(n) --> n = number of rows

#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals){
    vector<vector<int>> merged_intervals;
    if(intervals.size()==0)
        return merged_intervals;
    sort(intervals.begin(),intervals.end());
    vector<int> temp_interval=intervals[0];
    int ro = intervals.size();
    for(int i = 0; i < ro; i++){
        if(temp_interval[1]>intervals[i][0])
            temp_interval[1]=max(temp_interval[1],intervals[i][1]);
        else{
            merged_intervals.push_back(temp_interval);
            temp_interval=intervals[i];
        }
    }
    merged_intervals.push_back(temp_interval);
    return merged_intervals;
}
int main(){
    int ro,co,input;
    cin >> ro >> co;
    vector<vector<int>> vec(ro);
    for(int i = 0; i < ro; i++){
        vec[i]=vector<int>(co);
        for(int j = 0; j < co; j++){
            cin >> vec[i][j];
        }
    }
    vector<vector<int>> res;
    res = merge(vec);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
