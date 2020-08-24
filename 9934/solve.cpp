// https://www.acmicpc.net/problem/9934
// 완전 이진 트리
// Written in C++ langs
// 2020. 08. 24.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

queue<int> INPUT;
vector<int> TREE;
int K;

void insert(int cnode, int depth){
    if(depth > K) return;
    
    insert(cnode*2, depth+1);
    
    TREE[cnode] = INPUT.front();
    INPUT.pop();
    
    insert(cnode*2+1, depth+1);
}

void print(int cnode, int depth){
    if(depth > K) return;
    
    for(int i=0; i<pow(2,depth-1); i++){
        cout << TREE[cnode+i] << " ";
    }
    cout << "\n";
    
    print(cnode*2, depth+1);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    int size = (1<<K)-1;
    
    int in;
    for(int i=0; i<size; i++){
        cin >> in;
        INPUT.push(in);
    }
    
    TREE.resize(size+1);
    
    insert(1, 1);
    print(1,1);
    
    return 0;
    
}

