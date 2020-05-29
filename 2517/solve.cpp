// https://www.acmicpc.net/problem/2517
// 달리기
// Written in C++ langs
// 2020. 05. 29.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, int>> A;
vector<long long> TREE;
int N;

long long init(vector<long long> &tree, vector<long long> &a, int node, int start, int end){
    if(start == end){
        return tree[node] = start;
    }
   
    return tree[node] = init(tree, a, node*2, start, (start+end)/2) + init(tree, a, node*2+1, (start+end)/2+1, end);
}

void update(vector<long long> &tree, int node, int start, int end, int index, int diff){
    if(index<start || index>end) return;
    
    tree[node] += diff;
    
    if(start != end){
        update(tree, node*2, start, (start+end)/2, index, diff);
        update(tree, node*2+1, (start+end)/2+1, end, index, diff);
    }
}

long long query(vector<long long> &tree, int node, int start, int end, int left, int right){
    if(right<start || left>end) return 0;
    
    if(left<=start && right>=end) return tree[node];
    
    return query(tree, node*2, start, (start+end)/2, left, right) + query(tree, node*2+1, (start+end)/2+1, end, left, right);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    int h = (int)ceil(log2(N));
    int tree_size = 1<<(h+1);
    TREE.resize(tree_size);
    A.resize(N);

    for(int i=0; i<N; i++){
        cin >> A[i].first;
        A[i].second = i;
    }
    
    sort(A.begin(), A.end());
    for(int i=0; i<A.size(); i++){
        A[i].first = i;
    }
    
    // A.first : 순서 값이 높으면 기대치가 높음
    // B.second : 입력 된 순서 ( 시작 순서 )
    sort(A.begin(), A.end(), [](const pair<int, int> &a, const pair<int, int> &b){return a.second < b.second;});
    
    for(int i=0; i<A.size(); i++){
        cout << query(TREE, 1, 0, N-1, A[i].first, N-1)+1 << "\n";
        update(TREE, 1, 0, N-1, A[i].first, 1);
    }
    
    return 0;
    
}

