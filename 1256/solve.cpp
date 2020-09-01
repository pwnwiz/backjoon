// https://www.acmicpc.net/problem/1256
// 사전
// Written in C++ langs
// 2020. 09. 01.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int N, M, K;
int DP[101][101];
bool flag = false;

// REF : https://jaimemin.tistory.com/572
// 조합의 개수를 구하는데 사용됨
// DP는 a와 z의 개수를 사용해서 만들 수 있는 조합의 수를 의미
int getWordCount(int a, int z){
    if(a == 0 || z == 0) return 1;
    
    if(DP[a][z] != -1) return DP[a][z];
    
    // a 또는 z를 택하는 경우와 단어가 존재하지 않은 경우를 선택
    return DP[a][z] = min(getWordCount(a-1, z)+getWordCount(a, z-1), 1000000000+1);
}

// 조합의 개수를 확인하여 a또는 z를 사용하여 재귀 분기
string RESULT;
void getWord(int a, int z, int skip){
    if(a == 0){
        for(int i=0; i<z; i++){
            RESULT += 'z';
        }
        return;
    }
    
    if(z == 0){
        for(int j=0; j<a; j++){
            RESULT += 'a';
        }
        return;
    }
    
    // 현재 a를 넣었을 경우에 목표 지점보다 뒤의 단어인지 확인
    // 조합의 개수가 범위 안일 경우 현재 글자 a
    // 범위 밖이며 K보다 작은 경우 현재 글자 z
    // flag는 조합이 불가능한 경우를 의미
    auto idx = getWordCount(a-1, z);
    
    if(skip<idx){
        RESULT += 'a';
        getWord(a-1, z, skip);
    } else if(skip <= 1000000000){
        RESULT += 'z';
        getWord(a, z-1, skip-idx);
    } else {
        flag = true;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    memset(DP, -1, sizeof(DP));
    
    cin >> N >> M >> K;
    
    if(getWordCount(N, M) < K){
        flag = true;
    } else {
        getWord(N, M, K-1);
    }
    
    flag ? cout << "-1\n" : cout << RESULT << "\n";
  
    return 0;
    
}

