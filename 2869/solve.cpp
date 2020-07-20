// https://www.acmicpc.net/problem/2869
// 달팽이는 올라가고 싶다
// Written in C++ langs
// 2020. 07. 20.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

long long A, B, V;
long long DIFF;
long long DAY = 1;

void bisect(long long l, long long r){
    if(l <= r){
        long long mid = (l+r)/2;
        long long days = mid * DIFF;
        
        // 낮에 꼭대기에 올라간 경우
        if(days+B < V){
            bisect(mid+1, r);
        } else {
            DAY = mid;
            bisect(l, mid-1);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> A >> B >> V;
    DIFF = A-B;
    
    bisect(1, V/DIFF+1);
    cout << DAY << "\n";
    
    return 0;
    
}

