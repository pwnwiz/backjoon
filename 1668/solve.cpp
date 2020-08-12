// https://www.acmicpc.net/problem/1668
// 트로피 진열
// Written in C++ langs
// 2020. 08. 12.
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

    vector<int> trophy;
    
    cin >> N;
    
    int input;
    for(int i=0; i<N; i++){
        cin >> input;
        trophy.push_back(input);
    }
        
    int l = 1;
    int r = 1;
    
    int cur = trophy[0];
    for(int i=1; i<trophy.size(); i++){
        if(trophy[i] > cur){
            cur = trophy[i];
            l++;
        }
    }
    
    reverse(trophy.begin(), trophy.end());
    
    cur = trophy[0];
    for(int i=1; i<trophy.size(); i++){
        if(trophy[i] > cur){
            cur = trophy[i];
            r++;
        }
    }
    
    cout << l << "\n";
    cout << r << "\n";
    
    return 0;
    
}

