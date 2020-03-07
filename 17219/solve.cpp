// https://www.acmicpc.net/problem/17219
// 비밀번호 찾기
// Written in C++ langs
// 2020. 03. 07.
// Wizley

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<string,string> ACCOUNT;
string site, password;

int N, M;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> site >> password;
        ACCOUNT.insert(make_pair(site,password));
    }
    
    for(int i=0; i<M; i++){
        cin >> site;
        cout << ACCOUNT.find(site)->second << "\n";
    }
    
    
    return 0;
    
}

