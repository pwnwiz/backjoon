// https://www.acmicpc.net/problem/1551
// 수열의 변화
// Written in C++ langs
// 2020. 05. 11.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> VC;
int N, M;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string input;
    cin >> N >> M;
    cin >> input;
    
    string a = "";
    for(int i=0; i<input.size(); i++){
        if(input[i] == ','){
            VC.push_back(stoi(a));
            a = "";
        }
        else{
            a += input[i];
        }
    }

    if(a.size() >= 1){
        VC.push_back(stoi(a));
    } else{
        VC.push_back(0);
    }
    
    for(int i=0; i<M; i++){
        vector<int> VC2;
        for(int j=0; j<VC.size(); j++){
            if(j+1 == VC.size()) break;
            VC2.push_back(VC[j+1]-VC[j]);
        }
        VC = VC2;
        VC2.clear();
    }
    
    for(int i=0; i<VC.size(); i++){
        cout << VC[i];
        if(i+1 < VC.size()) cout << ",";
    }
    cout << "\n";
    
    return 0;
    
}

