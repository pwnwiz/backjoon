// https://www.acmicpc.net/problem/10974
// 모든 순열
// Written in C++ langs
// 2020. 09. 28.
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

    cin >> N;
    
    vector<int> numbers(N);

    for(int i=1; i<=N; i++){
        numbers[i-1] = i;
    }
   
    do {
        for(auto n : numbers){
            cout << n << " ";
        }
        cout << "\n";
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    
    return 0;
    
}

