// https://www.acmicpc.net/problem/2042
// 구간 합 구하기
// Written in C++ langs
// 2020. 05. 27.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

vector<long long> TREE;
vector<long long> A;
int N, M, K;

// a : 배열 A
// tree : 세그먼트 트리
// node : 트리의 노드 번호
// start ~ end : node가 담단하는 합의 범위
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end){
    // leaf node
    if (start == end){
        return tree[node] = a[start];
    }
    
    // leaf node가 아닐 경우 다시 범위 조정
    // 0 ~ 3 인 경우 0~1, 2~3으로 나눠서 재귀함
    // h의 경우 현재 노드의 자식이기 때문에 node*2, node*2+1이 됨
    else {
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
    }
}

// start ~ end : node가 담당하는 구간
// left ~ right : 합을 구해야 하는 구간
// 가능한 조건
// - [left, right] 가 [start, end] 와 겹치지 않은 경우
// - [left, right] 가 [start, end] 를 포함하는 경우
// - [start, end] 가 [left, right] 를 포함하는 경우
// - [left, right] 와 [start, end] 가 겹쳐있는 경우
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right){
    if(right<start || left>end) return 0;
    
    // left/right 가 [0, 6] 이고 현재 start/end 가 [0, 4] 인 상황과 같은 경우
    // 자식 노드들을 다 더한 값이 필요하기에 현재 node 값 리턴
    if(left<=start && right>=end){
        return tree[node];
    }
    
    // start/end가 [0, 9] 인 경우 [0, 6]을 구하기 위해선 자식 노드로 구간을 좁혀야 됨
    // [0, 4] 와 [5, 9]로 범위를 나누어 재귀 호출
    return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}

// 어떤 값을 변경하면 그 구간내의 모든 노드를 변경해야됨
// index -> val로 변경할 경우 diff를 구해야 됨
// 경우의 수
// [start, end] 에 index가 포함되지 않는 경우
// [start, end] 에 index가 포함되는 경우
// 포함되는 경우에는 diff만큼 증가시키면 합에 대한 변경이 가능
// 리프 노드가 아닌 경우 자식도 변경해주어야 되기 때문에 검사 과정 필요
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff){
    // index가 범위에 존재하지 않는 경우
    if(index<start || index>end) return;
    
    // 현재 범위에 포함되는 경우 diff를 더함으로써 값 최신화
    tree[node] = tree[node] + diff;
    
    // leaf node가 아닌 경우 내려가면서 경로를 다 최신해 주어야 됨
    if(start!=end){
        update(tree, node*2, start, (start+end)/2, index, diff);
        update(tree, node*2+1, (start+end)/2+1, end, index, diff);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    
    // 세그먼트 트리 높이
    int h = (int)ceil(log2(N));
    int tree_size = (1<<(h+1));
    TREE.resize(tree_size);
    
    int x;
    for(int i=0; i<N; i++){
        cin >> x;
        A.push_back(x);
    }
    
    // 세그먼트 트리 생성
    init(A, TREE, 1, 0, N-1);
    
    long long a, b, c;
    for(int i=0; i<M+K; i++){
        cin >> a >> b >> c;
    
        if(a==1){
            long long diff = c - A[b-1];
            A[b-1] = c;
            update(TREE, 1, 0, N-1, b-1, diff);
        }
        else if(a==2){
            long long result = sum(TREE, 1, 0, N-1, b-1, c-1);
            cout << result << "\n";
        }
    }

    return 0;
    
}


