// https://www.acmicpc.net/problem/5597
// 과제 안 내신 분..?
// Written in C++ langs
// 2020. 02. 03.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int ATTENDENCE[31]={0,};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int no;
    
    for(int i=0; i<28; i++){
        cin >> no;
        ATTENDENCE[no]++;
    }
    
    for(int i=1; i<=30; i++){
        if(!ATTENDENCE[i]) cout << i << "\n";
    }
    
}

