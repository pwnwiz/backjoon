// https://www.acmicpc.net/problem/12904
// A와 B
// Written in C++ langs
// 2020. 06. 11.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

string S;
string T;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S >> T;
    
    bool result = false;
    while(true){
        if(S.length()==T.length()){
            if(S == T) result = true;
            break;
        }
        
        char c = T[T.length()-1];
        T.pop_back();
        
        if(c == 'B') reverse(T.begin(), T.end());
    }

    cout << result << "\n";
    
    return 0;

}

