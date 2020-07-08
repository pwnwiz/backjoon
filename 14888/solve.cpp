// https://www.acmicpc.net/problem/14888
// 연산자 끼워넣기
// Written in C++ langs
// 2020. 07. 08.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> NO;
vector<int> EXPRESSION;
int N;

int MAXV = -1000000001;
int MINV = 1000000001;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    int input;
    for(int n=0; n<N; n++){
        cin >> input;
        NO.push_back(input);
    }
    
    for(int i=0; i<4; i++){
        cin >> input;
        EXPRESSION.push_back(input);
    }
    
    vector<int> combination;
    for(int i=0; i<EXPRESSION.size(); i++){
        for(int j=0; j<EXPRESSION.at(i); j++){
            combination.push_back(i);
        }
    }
    
    do {
        int res = NO[0];
        for(int c=0; c<combination.size(); c++){
            switch (combination[c]) {
                case 0:
                    res += NO[c+1];
                    break;
                case 1:
                    res -= NO[c+1];
                    break;
                case 2:
                    res *= NO[c+1];
                    break;
                case 3:
                    res /= NO[c+1];
                    break;
            }
        }
        MAXV = max(MAXV, res);
        MINV = min(MINV, res);
        
    } while(next_permutation(combination.begin(), combination.end()));
    
    cout << MAXV << "\n" << MINV << "\n";
    
    return 0;

}

