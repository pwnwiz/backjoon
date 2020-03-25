// https://www.acmicpc.net/problem/2632
// 피자판매
// Written in C++ langs
// 2020. 03. 25.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int SIZE;
int SIZE_A, SIZE_B;
int A[1001]={0,};
int B[1001]={0,};
vector<int> PIECES_A;
vector<int> PIECES_B;
int RESULT = 0;

void getPieces_A(){
    for(int total_count=1; total_count<SIZE_A; total_count++){
        for(int i=0; i<SIZE_A; i++){
            int idx = i;
            int count = 0;
            int sum = 0;
            while(count < total_count){
                if(idx == SIZE_A){
                    idx = 0;
                }
                sum += A[idx];
                idx++;
                count++;
            }
            PIECES_A.push_back(sum);
        }
    }
    
    int totalsum = 0;
    for(int i=0; i<SIZE_A; i++){
        totalsum += A[i];
    }
    PIECES_A.push_back(totalsum);
}

void getPieces_B(){
    for(int total_count=1; total_count<SIZE_B; total_count++){
        for(int i=0; i<SIZE_B; i++){
            int idx = i;
            int count = 0;
            int sum = 0;
            while(count < total_count){
                if(idx == SIZE_B){
                    idx = 0;
                }
                sum += B[idx];
                idx++;
                count++;
            }
            PIECES_B.push_back(sum);
        }
    }
    
    int totalsum = 0;
    for(int i=0; i<SIZE_B; i++){
        totalsum += B[i];
    }
    PIECES_B.push_back(totalsum);
    
}



int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> SIZE >> SIZE_A >> SIZE_B;
    
    for(int i=0; i<SIZE_A; i++){
        cin >> A[i];
    }

    for(int i=0; i<SIZE_B; i++){
        cin >> B[i];
    }
    
    getPieces_A();
    getPieces_B();

    sort(PIECES_B.begin(), PIECES_B.end());
    
    for(int i=0; i<PIECES_A.size(); i++){
        int value = SIZE - PIECES_A[i];
        if(value == 0){
            RESULT += 1;
        }
        else {
            auto range = equal_range(PIECES_B.begin(), PIECES_B.end(), value);
            RESULT += range.second - range.first;
        }
    }
    
    for(int i=0; i<PIECES_B.size(); i++){
        if(SIZE - PIECES_B[i] == 0){
            RESULT += 1;
        }
    }
    
    cout << RESULT << "\n";
    
    return 0;
    
}

