// https://www.acmicpc.net/problem/1015
// 수열 정렬
// Written in C++ langs
// 2020. 08. 05.
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
    
    vector<int> P(N);
    vector<pair<int,int>> A;
    
    int in;
    for(int i=0; i<N; i++){
        cin >> in;
        A.push_back(make_pair(in, i));
    }
    
    sort(A.begin(), A.end());
    
    for(int i=0; i<A.size(); i++){
        P[A[i].second] = i;
    }
    
    for(auto p: P){
        cout << p << " ";
    }
    cout << "\n";
    
    
    return 0;
    
}

