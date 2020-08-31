// https://www.acmicpc.net/problem/11812
// K진 트리
// Written in C++ langs
// 2020. 08. 31.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long N;
int K, Q;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K >> Q;
    
    long long a, b;
    for(int i=0; i<Q; i++){
        int cnt = 0;
        
        cin >> a >> b;
        
        // worst case
        if(K == 1){
            cout << abs(a-b) << "\n";
            continue;
        }
    
        while(a != b){
            if(a > b){
                a = (a - 2)/K + 1;
            } else {
                b = (b - 2)/K + 1;
            }
            cnt++;
        }
        
        cout << cnt << "\n";
    }
    
    return 0;
}

