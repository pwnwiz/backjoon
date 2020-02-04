// https://www.acmicpc.net/problem/1212
// 8진수 2진수
// Written in C++ langs
// 2020. 02. 04.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

string input_8;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> input_8;
    
    if(input_8 == "0") cout << "0\n";
    
    else{
        for(int i=0; i<input_8.size(); i++){
            switch(input_8[i]-'0'){
                case 0:
                    cout << "000";
                    break;
                case 1:
                    if(i==0) cout << "1";
                    else cout << "001";
                    break;
                case 2:
                    if(i==0) cout << "10";
                    else cout << "010";
                    break;
                case 3:
                    if(i==0) cout << "11";
                    else cout << "011";
                    break;
                case 4:
                    cout << "100";
                    break;
                case 5:
                    cout << "101";
                    break;
                case 6:
                    cout << "110";
                    break;
                case 7:
                    cout << "111";
                    break;
            }
        }
    }
    cout << "\n";
    return 0;
}

