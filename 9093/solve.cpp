// https://www.acmicpc.net/problem/9093
// 단어 뒤집기
// Written in C++ langs
// 2020. 10. 14.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream>

int N;

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    string input;
    
    cin.ignore();
    for(int i=0; i<N; i++){
        getline(cin, input, '\n');
        
        string word;
        for(istringstream is(input); is>>word; ){
            reverse(word.begin(), word.end());
            cout << word << " ";
        }
        cout << "\n";

    }
}

