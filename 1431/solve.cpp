// https://www.acmicpc.net/problem/1431
// 시리얼 번호
// Written in C++ langs
// 2020. 08. 05.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

bool compare(const string &a, const string &b){
    if(a.length() != b.length()) return a.length() < b.length();
    
    else {
        int av = 0;
        int bv = 0;
        for(int i=0; i<a.length(); i++){
            if(a[i] >= '0' && a[i] <= '9'){
                av += a[i] - '0';
            }
        }
        for(int j=0; j<b.length(); j++){
            if(b[j] >= '0' && b[j] <= '9'){
                bv += b[j] - '0';
            }
        }
        if(av != bv) return av < bv;
        
        return a<b;
    }
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
    
    for(auto word : input){
        cout << word << "\n";
    }
    
    return 0;
    
}

