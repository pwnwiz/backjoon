// https://www.acmicpc.net/problem/1448
// 삼각형 만들기
// Written in C++ langs
// 2020. 08. 14.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int RESULT = -1;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    vector<int> side;
    
    int s;
    for(int i=0; i<N; i++){
        cin >> s;
        side.push_back(s);
    }

    sort(side.begin(), side.end(), greater<>());

    int x = side[0];
    int y = side[1];
    for(int i=2; i<side.size(); i++){
        int z = side[i];
        if(x+y>z && x+z>y && y+z>x){
            RESULT = x+y+z;
            break;
        } else {
            x = y;
            y = z;
        }
    }
    cout << RESULT << "\n";
    
    return 0;
}

