// https://www.acmicpc.net/problem/1181
// 단어 정렬
// Written in C++ langs
// 2020. 08. 04.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N;

bool compare(string &A, string &B){
    if(A.length() == B.length()){
        return A < B;
    }
    return A.length() < B.length();
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    vector<string> input;
    
    string in;
    for(int i=0; i<N; i++){
        cin >> in;
        input.push_back(in);
    }
    
    sort(input.begin(), input.end(), compare);
    
    string tmp = "";
    for(int i=0; i<input.size(); i++){
        if(tmp == input[i]) continue;
        
        tmp = input[i];
        cout << input[i] << "\n";
    }
    
    return 0;
}

