// https://www.acmicpc.net/problem/2448
// 별 찍기 - 11
// Written in C++ langs
// 2020. 03. 02.
// Wizley

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int N;
int CUR=0;

char TRIANGLE[10000][10000]={0,};
char STAR[3][5] = { {' ', ' ', '*', ' ', ' '},{' ', '*', ' ', '*', ' '}, {'*', '*', '*', '*', '*'}};

void firstTriangle(int size){
    for(int i=0; i<3; i++){
        memcpy(TRIANGLE[i]+(N-3), STAR[i], 5);
        TRIANGLE[i][N*2-1]='\0';
        puts(TRIANGLE[i]);
    }
    CUR=3;
    if(size==3) exit(0);
}

void makeTriangle(int size, int level, int copysize, int indent){
    for(int i=0; i<level; i++){
        memcpy(TRIANGLE[i+level]+indent, TRIANGLE[i]+N-level, copysize);
        memcpy(TRIANGLE[i+level]+indent+copysize+1, TRIANGLE[i]+N-level, copysize);
        TRIANGLE[i+level][N*2-1]='\0';
        puts(TRIANGLE[i+level]);
        CUR++;
    }
    
    if(CUR!=size){
        makeTriangle(size, level*2, copysize*2+1, indent-level*2);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(TRIANGLE, ' ', sizeof(TRIANGLE));
    
    cin >> N;
    firstTriangle(N);
    makeTriangle(N, 3, 5, N-6);

    return 0;
}


