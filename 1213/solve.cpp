// https://www.acmicpc.net/problem/1213
// 팰린드롬 만들기
// Written in C++ langs
// 2020. 08. 06.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int ALPHABET[26];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    
    cin >> input;
    
    for(int i=0; i<input.size(); i++){
        ALPHABET[input[i]-'A'] += 1;
    }
    
    deque<char> frontque;
    deque<char> backque;
    
    if(input.size() % 2 == 0){
        for(int i=0; i<26; i++){
            if(ALPHABET[i] != 0 && ALPHABET[i] % 2 == 1){
                cout << "I'm Sorry Hansoo\n";
                return 0;
            }
        }
        
        for(int i=25; i>=0; i--){
            int cnt = ALPHABET[i];
            
            for(int j=0; j<cnt; j+=2){
                frontque.push_front('A'+i);
                backque.push_back('A'+i);
            }
        }
        
        for(auto q : frontque){
            cout << q;
        }
        for(auto q : backque){
            cout << q;
        }
        cout << "\n";
        
    } else {
        int odd = 0;
        int pos = 0;
        
        for(int i=0; i<26; i++){
            if(ALPHABET[i] != 0 && ALPHABET[i] % 2 == 1){
                pos = i;
                odd++;
            }
        }
        
        if(odd != 1){
            cout << "I'm Sorry Hansoo\n";
            return 0;
        }
        
        for(int i=25; i>=0; i--){
            int cnt = ALPHABET[i];

            if(i==pos){
                if(ALPHABET[i]<=1) continue;
                else {
                    for(int j=0; j<cnt/2; j++){
                        frontque.push_front('A'+i);
                        backque.push_back('A'+i);
                    }
                }
            }
            else {
                for(int j=0; j<cnt; j+=2){
                    frontque.push_front('A'+i);
                    backque.push_back('A'+i);
                }
            }
        }
        
        for(auto q : frontque){
            cout << q;
        }
        
        cout << char('A' + pos);
        
        for(auto q : backque){
            cout << q;
        }
        cout << "\n";
                
    }
    
    return 0;
    
}

