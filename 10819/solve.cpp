// https://www.acmicpc.net/problem/10819
// 차이를 최대로
// Written in C++ langs
// 2020. 03. 10.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;

vector<int> ARR;
int RESULT;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    int tmp;
    for(int i=0; i<N; i++){
        cin >> tmp;
        ARR.push_back(tmp);
    }
    sort(ARR.begin(), ARR.end());
    
    do{
        int result = 0;
        for(int i=0; i<ARR.size()-1; i++){
            result += abs(ARR[i] - ARR[i+1]);
        }
        (result > RESULT) ? RESULT = result : result = 0;
    } while(next_permutation(ARR.begin(), ARR.end()));
    
    cout << RESULT << "\n";
    
    return 0;
    
}

