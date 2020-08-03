// https://www.acmicpc.net/problem/1062
// 가르침
// Written in C++ langs
// 2020. 08. 03.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> chars;
bool CHAR[26][2];
int N, K;

int RESULT = 0;

int getCharCount(){
    int count = 0;
    for(int i=0; i<26; i++){
        if(CHAR[i][0]) count ++;
    }
    return count;
}

int getAvailCount(){
    int count = 0;
    for(int i=0; i<26; i++){
        if(CHAR[i][1]) count ++;
    }
    return count;
}

void backtracking(int pos, int size){
    if(size == getAvailCount() || size == K){
        int cnt = 0;
        for(auto words : chars){
            bool flag = true;
            for(int i=4; i<words.size()-4; i++){
                if(!CHAR[words[i]-'a'][0]){
                    flag = false;
                    break;
                }
            }
            
            if(flag){
                cnt++;
            }
            
        }
        
        RESULT = max(RESULT, cnt);
        return;
    }
    
    else {
        for(int i=pos; i<26; i++){
            if(!CHAR[i][0] && CHAR[i][1]){
                CHAR[i][0] = true;
                backtracking(i, size+1);
                CHAR[i][0] = false;
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    
    string init = "antatica";
    for(auto i : init){
        CHAR[i-'a'][0] = true;
        CHAR[i-'a'][1] = true;
    }
    
    string input;
    for(int i=0; i<N; i++){
        cin >> input;
        chars.push_back(input);
        
        if(input.size() > 8){
            for(int j=4; j<input.size()-4; j++){
                CHAR[input[j]-'a'][1] = true;
            }
        }
    }
    
    if(K < 5){
        cout << "0\n";
        return 0;
    }
    
    backtracking(0, getCharCount());

    cout << RESULT << "\n";

    return 0;
    
}

