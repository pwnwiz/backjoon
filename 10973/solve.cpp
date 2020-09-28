// https://www.acmicpc.net/problem/10973
// 이전 순열
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

    for(int i=0; i<N; i++){
        cin >> numbers[i];
    }
    
    vector<int> sorted_numbers = numbers;
    sort(sorted_numbers.begin(), sorted_numbers.end());

    if(numbers == sorted_numbers){
        cout << "-1\n";
        return 0;
    }
    
    prev_permutation(numbers.begin(), numbers.end());

    for(auto n : numbers){
        cout << n << " ";
    }
    
    return 0;
    
}

