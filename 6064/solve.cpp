// https://www.acmicpc.net/problem/6064
// 카잉 달력
// Written in C++ langs
// 2020. 10. 05.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T;
int M, N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    int x, y;
    
    for(int i=0; i<T; i++){
        cin >> M >> N >> x >> y;
        
        int loop = 0;
        while(true){
            long long cx = x + (loop++ * M);
            int cy = cx % N;
            
            if(cy == y || (!cy && N==y)){
                cout << cx << "\n";
                break;
            }
            
            if(M*N <= cx){
                cout << "-1\n";
                break;
            }
        }
    }
    
    return 0;
}

