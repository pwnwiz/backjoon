// https://www.acmicpc.net/problem/14225
// 부분수열의 합
// Written in C++ langs
// 2020. 11. 06.
// Wizley

#include<algorithm>
#include<iostream>
#include<vector>
#include<set>

using namespace std;

bool SET[2000001];
vector<int> V;
vector<bool> USED;
int S;

void backtracking(int index, long long sum){
    if(index == V.size()){
        SET[sum] = true;
        return;
    }
    
    backtracking(index+1, sum+V[index]);
    backtracking(index+1, sum);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> S;
    V.resize(S);
    USED.resize(S);
    
    for(int s=0; s<S; s++){
        cin >> V[s];
    }

    backtracking(0, 0);
    
    int idx = 1;
    while(true){
        if(!SET[idx]){
            cout << idx << "\n";
            break;
        }
        idx++;
    }
    return 0;
}

