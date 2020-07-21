// https://www.acmicpc.net/problem/2872
// 우리집엔 도서관이 있어
// Written in C++ langs
// 2020. 07. 21.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    vector<int> A;
    
    int input;
    for(int i=0; i<N; i++){
        cin >> input;
        A.push_back(input);
    }
    
    int cur = N;
    for(int i=N-1; i>=0; i--){
        if(A[i] == cur) cur --;
    }
    
    cout << cur << "\n";
    
    return 0;
    
}

