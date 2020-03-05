// https://www.acmicpc.net/problem/10610
// 30
// Written in C++ langs
// 2020. 03. 05.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string N;

bool compare(int a, int b){
    return a>b;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> N;
    int sum=0;
    bool hasZero=false;
    
    for(int i=0; i<N.size(); i++){
        sum += N[i] - '0';
        if(N[i] == '0'){
            hasZero = true;
        }
    }
    
    if(!hasZero){
        cout << "-1\n";
    }
    
    else if(sum%3!=0){
        cout << "-1\n";
    }
    
    else{
        sort(N.begin(), N.end(), compare);
        cout << N << "\n";
    }
}

