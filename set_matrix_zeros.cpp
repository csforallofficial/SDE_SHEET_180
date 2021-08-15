//1st approach - Time --> O((n*m)(n+m))       n --> row size    m --> column size

#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    int ro, co;
    cin >> ro >> co;
    vector<vector<int>> vec(ro);
    for(int i = 0; i < ro; i++){
        vec[i] = vector<int>(co);
        for(int j = 0; j < co; j++)
            cin >> vec[i][j];
    }
    for(int i = 0; i < ro; i++){
        for(int j = 0; j < co; j++){
            if(vec[i][j]==0){
                for(int x=0,y=0; x < ro && y < co; x++,y++){
                    if(vec[x][j]!=0 || vec[i][y]!=0){
                        vec[x][j] = -1;
                        vec[i][y] = -1;
                    }
                }
            }
        }
    }
    for(int i = 0; i < ro; i++){
        for(int j = 0; j < co; j++){
            if(vec[i][j]==-1)
                vec[i][j] = 0;
        }
    }
    for(int i = 0; i < ro; i++){
        for(int j = 0; j < co; j++){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//2nd approach - Time --> O(m*n)    Space --> O(n+m)

#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    int ro, co;
    cin >> ro >> co;
    vector<vector<int>> vec(ro);
    for(int i = 0; i < ro; i++){
        vec[i] = vector<int>(co);
        for(int j = 0; j < co; j++)
            cin >> vec[i][j];
    }
    int row[ro];
    int col[co];
    for(int i = 0; i < ro; i++){
        for(int j = 0; j < co; j++){
            if(vec[i][j]==0){
                col[j] = 0;
                row[i] = 0;
            }
        }
    }
    for(int i = 0; i < ro; i++){
        for(int j = 0; j < co; j++){
            if(col[j]==0 || row[i]==0)
                vec[i][j] = 0;
        }
    }
    
    for(int i = 0; i < ro; i++){
        for(int j = 0; j < co; j++){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//3rd approach- Time --> O(n*m)   Space --> O(1)

#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    int ro, co;
    cin >> ro >> co;
    vector<vector<int>> vec(ro);
    for(int i = 0; i < ro; i++){
        vec[i] = vector<int>(co);
        for(int j = 0; j < co; j++)
            cin >> vec[i][j];
    }
    
    int col0 = 1;
    for(int i = 0; i < ro; i++){
        if(vec[i][0]==0)
            col0 = 0;
        for(int j = 1; j < co; j++){
            if(vec[i][j]==0)
                vec[i][0] = vec[0][j] = 0;
        }
    }
    
    for(int i = ro-1; i >= 0; i--){
        for(int j = co-1; j >= 1; j--){
            if(vec[i][0]==0 || vec[0][j]==0)
                vec[i][j] = 0;
        }
        if(col0 == 0)
            vec[i][0] = 0;
    }
    
    for(int i = 0; i < ro; i++){
        for(int j = 0; j < co; j++){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
