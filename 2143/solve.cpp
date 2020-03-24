// https://www.acmicpc.net/problem/2143
// 두 배열의 합
// Written in C++ langs
// 2020. 03. 24.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

long long T;
int A, B;
vector<int> ARR_A;
vector<int> ARR_B;
vector<int> SET_A;
vector<int> SET_B;

long long COUNT=0;
int BEGIN=0;
int END=0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    cin >> A;
    int tmp;
    for(int i=0; i<A; i++){
        cin >> tmp;
        ARR_A.push_back(tmp);
    }
    
    cin >> B;
    for(int i=0; i<B; i++){
        cin >> tmp;
        ARR_B.push_back(tmp);
    }
    
    for(int i=0; i<ARR_A.size(); i++){
        int sum = 0;
        for(int j=i; j<ARR_A.size(); j++){
            sum += ARR_A[j];
            SET_A.push_back(sum);
        }
    }
    
    for(int i=0; i<ARR_B.size(); i++){
        int sum = 0;
        for(int j=i; j<ARR_B.size(); j++){
            sum += ARR_B[j];
            SET_B.push_back(sum);
        }
    }

    sort(SET_B.begin(), SET_B.end());
    
    for(int val_A : SET_A){
        auto range = equal_range(SET_B.begin(), SET_B.end(), T-val_A);
        COUNT += range.second - range.first;
    }
    
    cout << COUNT << "\n";
    
    return 0;
    
}

