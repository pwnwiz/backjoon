// https://www.acmicpc.net/problem/2529
// 부등호
// Written in C++ langs
// 2020. 10. 05.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

vector<char> v;
long long MIN_V = LLONG_MAX;
long long MAX_V = LLONG_MIN;
string MIN_S = "";
string MAX_S = "";
int N;

bool used[10];
void backtracking(int pos, string &str){

    if(str.length() == v.size()+1){
        long long value = stol(str);
        
        if(MIN_V > value){
            MIN_V = value;
            MIN_S = str;
        }
        
        if(MAX_V < value){
            MAX_V = value;
            MAX_S = str;
        }
        return;
    }
    
    for(int i=0; i<10; i++){
        if(used[i]) continue;
        
        if(pos == 0){
            string next = str + to_string(i);
            used[i] = true;
            backtracking(pos+1, next);
            used[i] = false;
        } else {
            if(v[pos-1] == '<'){
                if(str.back()-'0' < i){
                    string next = str + to_string(i);
                    used[i] = true;
                    backtracking(pos+1, next);
                    used[i] = false;
                }
            } else {
                if(str.back()-'0' > i){
                    string next = str + to_string(i);
                    used[i] = true;
                    backtracking(pos+1, next);
                    used[i] = false;
                }
            }
        }
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    char c;
    for(int i=0; i<N; i++){
        cin >> c;
        v.push_back(c);
    }
    
    string str = "";
    backtracking(0, str);
    
    cout << MAX_S << "\n";
    cout << MIN_S << "\n";
    
    return 0;
}

