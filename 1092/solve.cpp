// https://www.acmicpc.net/problem/1092
// 배
// Written in C++ langs
// 2020. 04. 13.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int CRANE[50]={0,};
int MIN_COUNT[50]={0,};
vector<int> BOX;
int N, M;
int COUNT=0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> CRANE[i];
    }
    
    sort(CRANE, CRANE+N);
    
    cin >> M;
    int input;
    for(int i=0; i<M; i++){
        cin >> input;
        BOX.push_back(input);
    }
    
    sort(BOX.begin(), BOX.end());
    
    if(BOX[M-1]>CRANE[N-1]){
        cout << "-1\n";
        exit(0);
    }
    
    int idx = 0;
    for(int i=0; i<M; i++){
        while(BOX[i]>CRANE[idx]){
            idx++;
        }
        
        MIN_COUNT[idx]++;
    }
    
    while(!BOX.empty()){
        for(int i=0; i<N; i++){
            if(MIN_COUNT[i]){
                MIN_COUNT[i]--;
                BOX.erase(BOX.begin());
            }
            else{
                for(int j=i; j>=0; j--){
                    if(MIN_COUNT[j]){
                        MIN_COUNT[j]--;
                        BOX.erase(BOX.begin());
                        break;
                    }
                }
            }
        }
        COUNT++;
    }
    
    cout << COUNT << "\n";
    
    return 0;
    
}

