// https://www.acmicpc.net/problem/2357
// 최솟값과 최댓값
// Written in C++ langs
// 2020. 05. 27.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>

#define INF 1000000001

using namespace std;

vector<pair<long long, long long>> TREE;
vector<long long> A;

int N, M;

long long init_min(vector<pair<long long, long long>> &tree, vector<long long> &a, int node, int start, int end){
    if(start == end){
        return tree[node].first = a[start];
    }
    else {
        return tree[node].first = min(init_min(tree, a, node*2, start, (start+end)/2), init_min(tree, a, node*2+1, (start+end)/2+1, end));
    }
}

long long init_max(vector<pair<long long, long long>> &tree, vector<long long> &a, int node, int start, int end){
    if(start == end){
        return TREE[node].second = a[start];
    }
    else {
        return TREE[node].second = max(init_max(tree, a, node*2, start, (start+end)/2), init_max(tree, a, node*2+1, (start+end)/2+1, end));
    }
}

long long find_min(vector<pair<long long, long long>> &tree, int node, int start, int end, int left, int right){
    // 0으로 처리하면 제대로 된 값이 나오지 않음
    if(end<left || start>right) return INF;
    
    if(start>=left && end<=right) return tree[node].first;
    
    return min(find_min(tree, node*2, start, (start+end)/2, left, right), find_min(tree, node*2+1, (start+end)/2+1, end, left, right));
}

long long find_max(vector<pair<long long, long long>> &tree, int node, int start, int end, int left, int right){
    if(end<left || start>right) return 0;
    
    if(start>=left && end<=right) return tree[node].second;
    
    return max(find_max(tree, node*2, start, (start+end)/2, left, right), find_max(tree, node*2+1, (start+end)/2+1, end, left, right));
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    int h = ceil(log2(N));
    int tree_size = (1<<(h+1));
    TREE.resize(tree_size);
    
    long long x;
    for(int i=0; i<N; i++){
        cin >> x;
        A.push_back(x);
    }
    
    init_min(TREE, A, 1, 0, N-1);
    init_max(TREE, A, 1, 0, N-1);
        
    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        cout << find_min(TREE, 1, 0, N-1, a-1, b-1) << " " << find_max(TREE, 1, 0, N-1, a-1, b-1) << "\n";
    }
    
    
    return 0;
    
}

