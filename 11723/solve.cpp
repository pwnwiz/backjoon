// https://www.acmicpc.net/problem/11723
// 집합
// Written in C++ langs
// 2020. 09. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int bit = 0;
    
    cin >> N;
    
    string exp;
    int no;
    for(int i=0; i<N; i++){
        cin >> exp;
        
        if(exp == "add"){
            cin >> no;
            bit |= 1 << no;
        }
        
        else if(exp == "remove"){
            cin >> no;
            bit &= ~(1 << no);
        }
        
        else if(exp == "check"){
            cin >> no;
            if(bit & 1<<no){
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
        
        else if(exp == "toggle"){
            cin >> no;
            if(bit & 1<<no){
                bit &= ~(1 << no);
            } else {
                bit |= 1 << no;
            }
        }
        
        else if(exp == "all"){
            bit |= (1<<21)-1;
        }
        
        else if(exp == "empty"){
            bit = 0;
        }
    }
    
    return 0;
    
}

