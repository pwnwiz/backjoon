// https://www.acmicpc.net/problem/1026
// 보물
// Written in C++ langs
// 2020. 07. 08.
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
    
    vector<int> vec_a;
    vector<int> vec_b;
    
    int input;
    for(int i=0; i<N; i++){
        cin >> input;
        vec_a.push_back(input);
    }
    
    for(int i=0; i<N; i++){
        cin >> input;
        vec_b.push_back(input);
    }
    
    sort(vec_a.begin(), vec_a.end());
    sort(vec_b.begin(), vec_b.end());
    reverse(vec_b.begin(), vec_b.end());
    
    int res = 0;
    for(int i=0; i<N; i++){
        res += vec_a[i] * vec_b[i];
    }
    
    cout << res << "\n";

    return 0;
}

