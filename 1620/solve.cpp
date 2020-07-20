// https://www.acmicpc.net/problem/1620
// 나는야 포켓몬 마스터 이다솜
// Written in C++ langs
// 2020. 07. 20.
// Wizley

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N, M;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    map<string, int> pokemon;
    map<int, string> idx;
    
    cin >> N >> M;
    
    string input;
    for(int i=1; i<=N; i++){
        cin >> input;
        pokemon[input] = i;
        idx[i] = input;
    }
    
    for(int i=0; i<M; i++){
        cin >> input;
        
        if(input[0] >= '0' && input[0] <= '9'){
            int no = stoi(input);
            cout << idx[no] << "\n";
        } else {
            cout << pokemon[input] << "\n";
        }
    }
    
    return 0;
    
}

