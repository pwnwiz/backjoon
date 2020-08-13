// https://www.acmicpc.net/problem/1039
// 교환
// Written in C++ langs
// 2020. 08. 13.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int MAX = 0;

bool VISITED[11][1000000] = {0,};

void backtracking(int number, int cnt){
    
    if(cnt == K){
        MAX = max(MAX, number);
        return;
    }
    
    auto str = to_string(number);
    
    for(int i=0; i<str.length()-1; i++){
        for(int j=i+1; j<str.length(); j++){
            swap(str[i], str[j]);
            if(str[0] != '0' && !VISITED[cnt+1][stoi(str)]){
                VISITED[cnt+1][stoi(str)] = true;
                backtracking(stoi(str), cnt+1);
            }
            swap(str[i], str[j]);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    
    if(N<=10 || (N<100 && N%10==0)){
        cout << "-1\n";
        return 0;
    }

    backtracking(N, 0);
    
    cout << MAX << "\n";
}

