// https://www.acmicpc.net/problem/1059
// 수2
// Written in C++ langs
// 2020. 08. 12.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> set;
    
    cin >> N;
    int in;
    for(int i=0; i<N; i++){
        cin >> in;
        set.push_back(in);
    }
    
    sort(set.begin(), set.end());
    
    cin >> M;
   
    int l = 0;
    int r = 0;
    for(int i=0; i<set.size()-1; i++){
        if(set[i]<M && set[i+1]>M){
            l = set[i]+1;
            r = set[i+1]-1;
            break;
        }
    }
    
    if(!l && !r){
        if(M<set[0]){
            l = 1;
            r = set[0]-1;
        }
    }
    
    int result = 0;
    if(l && r){
        // [l,M]을 기준으로 [M,r]의 수를 결합
        result = (r-M+1) * (M-l);
        // [M,r]의 수를 더함
        result += (r-M);
    }
    
    cout << result << "\n";
}
