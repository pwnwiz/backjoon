// https://www.acmicpc.net/problem/5397
// 키로거
// Written in C++ langs
// 2020. 07. 13.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    string input;
    for(int n=0; n<N; n++){
        cin >> input;

        deque<char> deq;
        int pos = 0;
        
        for(int i=0; i<input.size(); i++){
            switch(input[i]){
                case '<':
                    if(pos>0){
                        pos--;
                    }
                    break;
                case '>':
                    if(pos<deq.size()){
                        pos++;
                    }
                    break;
                case '-':
                    if(pos>0 && pos<=deq.size()){
                        deq.erase(deq.begin()+pos-1);
                        pos--;
                    }
                    break;
                default:
                    deq.insert(deq.begin()+pos, input[i]);
                    pos++;
                    break;
            }
            
        }
        
        for(auto d : deq){
            cout << d;
        }
        cout << "\n";
        
    }
    
    return 0;
}

