// https://www.acmicpc.net/problem/1083
// 소트
// Written in C++ langs
// 2020. 07. 06.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

int N, S;
int ARR[50];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> ARR[i];
    }

    cin >> S;
        
    if(N==1){
        cout << ARR[0];
        return 0;
    }

    // range does not exceed N nor S
    int range = min(N, S+1);
    
    int mv = -1;
    int left = 0;
    int right = 0;
    
    for(int n=0; n<N; n++){
        if(S <= 0) break;
    
        // to find max value within range
        for(int l=left; l<range; l++){
            if(l >= N) break;
            
            if(mv<ARR[l]){
                mv = ARR[l];
                right = l;
            }
        }
        
        // swap range from right to left
        for(int c=right; c>left; c--){
            if(S<=0) break;
            swap(ARR[c], ARR[c-1]);
            S--;
        }
    
        left++;
        mv = -1;
        range = min(N, S+1+left);
    }
    
    for(int i=0; i<N; i++){
        cout << ARR[i] << " ";
    }
    cout << "\n";
    
    return 0;
}

