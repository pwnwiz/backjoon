// https://www.acmicpc.net/problem/15658
// 연산자 끼워넣기 (2)
// Written in C++ langs
// 2020. 09. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int MAXV = INT_MIN;
int MINV = INT_MAX;
int T;
vector<int> numbers;

int expression[4] = {0,};

void backtracking(int sum, int pos, int used[4]){

    if(pos == numbers.size()){
        MAXV = max(MAXV, sum);
        MINV = min(MINV, sum);
        return;
    }
    
    for(int i=0; i<4; i++){
        if(used[i]<expression[i]){
            auto tmp = sum;
            used[i] += 1;
            switch(i){
                case 0:
                    sum += numbers[pos];
                    backtracking(sum, pos+1, used);
                    break;
                case 1:
                    sum -= numbers[pos];
                    backtracking(sum, pos+1, used);
                    break;
                case 2:
                    sum *= numbers[pos];
                    backtracking(sum, pos+1, used);
                    break;
                case 3:
                    sum /= numbers[pos];
                    backtracking(sum, pos+1, used);
                    break;
            }
            used[i] -= 1;
            sum = tmp;
        }
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    numbers.resize(T);
    
    for(int i=0; i<T; i++){
        cin >> numbers[i];
    }
    
    for(int i=0; i<4; i++){
        cin >> expression[i];
    }
    
    int used[4] = {0,};
    backtracking(numbers[0], 1, used);
    
    cout << MAXV << "\n" << MINV << "\n";
    
    return 0;
    
}

