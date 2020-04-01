// https://www.acmicpc.net/problem/1758
// 알바생 강호
// Written in C++ langs
// 2020. 04. 01.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int PEOPLE[100001]={0,};
long long TIP = 0;

bool compare(int A, int B){
    return A > B;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> PEOPLE[i];
    }
    
    sort(PEOPLE, PEOPLE+N, compare);
    
    for(int i=0; i<N; i++){
        int tip = PEOPLE[i] - i;
        if(tip>0){
            TIP += PEOPLE[i] - i;
        }
    }
    
    cout << TIP << "\n";
    
    return 0;

}


