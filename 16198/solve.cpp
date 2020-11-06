// acmicpc.net/problem/16198
// 에너지 모으기
// Written in C++ langs
// 2020. 11. 06.
// Wizley

#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

vector<int> marble;
vector<int> used;
int N;

int result = 0;
void backtracking(vector<int> &v, int cnt, int energy){
    
    if(cnt == N-2){
        result = max(result, energy);
        return;
    }
    
    for(int i=1; i<v.size()-1; i++){
        auto v2 = v;
        int collected = v[i-1] * v[i+1];
        v2.erase(v2.begin()+i);
        
        backtracking(v2, cnt+1, energy+collected);
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    marble.resize(N);
    used.resize(N);
    
    for(int n=0; n<N; n++){
        cin >> marble[n];
    }
    
    backtracking(marble, 0, 0);
    
    cout << result << "\n";
    return 0;
}

