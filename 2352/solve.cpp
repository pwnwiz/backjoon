// https://www.acmicpc.net/problem/2352
// 반도체 설계
// Written in C++ langs
// 2020. 04. 03.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> LIS;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    LIS.push_back(0);
    
    cin >> N;
    int val;
    for(int i=0; i<N; i++){
        cin >> val;
        if(val > LIS.back()){
            LIS.push_back(val);
        }
        
        else{
            auto it = lower_bound(LIS.begin(), LIS.end(), val);
            *it = val;
        }
        
    }
    
    cout << LIS.size() - 1 << "\n";
    
    return 0;
    
}

