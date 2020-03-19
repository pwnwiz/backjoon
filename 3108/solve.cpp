// https://www.acmicpc.net/problem/3108
// 로고
// Written in C++ langs
// 2020. 03. 19.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int COUNT;

int x1[1001]={0,};
int x2[1001]={0,};
int y1[1001]={0,};
int y2[1001]={0,};
int VISITED[1001]={0,};

// AS START FROM (0,0)
int RESULT = -1;

bool isOverlap(int A, int B){
    // RECTANGLE A and B ARE NOT ON SAME XY
    if(x1[B] > x2[A] || y1[B] > y2[A]){
        return false;
    }
    
    // RECTANGLE A IS IN INSIDE OF RECTANGLE B
    if((x1[A] > x1[B]) && (y1[A] > y1[B]) && (x2[A] < x2[B]) && (y2[A] < y2[B])){
        return false;
    }
    
    swap(A, B);
    
    if(x1[B] > x2[A] || y1[B] > y2[A]){
        return false;
    }
    
    if((x1[A] > x1[B]) && (y1[A] > y1[B]) && (x2[A] < x2[B]) && (y2[A] < y2[B])){
        return false;
    }
    
    return true;
}

void dfs(int idx){
    VISITED[idx] = true;
    
    for(int i=1; i<=COUNT; i++){
        if(!VISITED[i]){
            if(isOverlap(idx, i)){
                dfs(i);
            }
        }
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> COUNT;
    
    for(int i=1; i<=COUNT; i++){
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        if(x1[i]>x2[i]) swap(x1, x2);
        if(y1[i]>y2[i]) swap(y1, y2);
    }
    
    for(int i=0; i<=COUNT; i++){
        if(!VISITED[i]){
            dfs(i);
            RESULT += 1;
        }
    }
    
    cout << RESULT << "\n";
    
    return 0;
    
}

