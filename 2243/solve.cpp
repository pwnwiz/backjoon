// https://www.acmicpc.net/problem/2243
// 사탕상자
// Written in C++ langs
// 2020. 05. 27.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>

#define CANDY 1000000

using namespace std;

vector<int> TREE;

int N;

void update(vector<int> &tree, int node, int start, int end, int index, int diff){
    if(index<start || index>end) return;
    
    // 음수일 경우 개수를 줄이고 양수일 경우 개수를 늘림
    tree[node] += diff;
    
    if(start != end){
        update(tree, node*2, start, (start+end)/2, index, diff);
        update(tree, node*2+1, (start+end)/2+1, end, index, diff);
    }
}

int query(vector<int> &tree, int node, int start, int end, int index){
    // 인덱스를 찾은 경우
    if(start == end){
        return start;
    }
    
    // 이분 탐색 수행
    // 왼쪽 노드가 가진 사탕수가 찾고자 하는 index 이상일 경우
    if(index <= tree[node*2]){
        return query(tree, node*2, start, (start+end)/2, index);
    }
    // 왼쪽 노드가 가진 사탕수가 찾고자 하는 index 개수보다 작아 오른쪽에 원하는 사탕이 있을 경우
    else {
        return query(tree, node*2+1, (start+end)/2+1, end, index-tree[node*2]);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    int h = (int)ceil(log2(CANDY));
    int tree_size = (1<<(h+1));
    TREE.resize(tree_size);
    
    int choice;
    for(int i=0; i<N; i++){
        cin >> choice;
        
        if(choice == 1){
            int idx;
            cin >> idx;
            
            // idx번째로 맛있는 사탕 꺼냄
            int result = query(TREE, 1, 0, CANDY-1, idx);
            
            // 사탕 개수 최신화
            update(TREE, 1, 0, CANDY-1, result, -1);
            
            cout << result << "\n";

        } else if(choice == 2){
            int flavor, count;
            cin >> flavor >> count;
            update(TREE, 1, 0, CANDY-1, flavor, count);
        }
    }
    
    return 0;
}


