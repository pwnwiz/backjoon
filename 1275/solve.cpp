// https://www.acmicpc.net/problem/1275
// 커피숍2
// Written in C++ langs
// 2020. 05. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

vector<long long> TREE;
vector<long long> A;

int N, Q;

long long init(vector<long long> &tree, vector<long long> &a, int node, int start, int end){
    if(start == end){
        return tree[node] = a[start];
    }
    return tree[node] = init(tree, a, node*2, start, (start+end)/2) + init(tree, a, node*2+1, (start+end)/2+1, end);
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right){
    if(left>end || right<start) return 0;
    
    if(start>=left && end<=right){
        return tree[node];
    }
    
    return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff){
    if(start>index || end<index) return;
    
    tree[node] += diff;
    
    if(start != end){
        update(tree, node*2, start, (start+end)/2, index, diff);
        update(tree, node*2+1, (start+end)/2+1, end, index, diff);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> Q;
    
    int h = (int)ceil(log2(N));
    int tree_size = 1<<(h+1);
    TREE.resize(tree_size);
    
    int v;
    for(int n=0; n<N; n++){
        cin >> v;
        A.push_back(v);
    }
    
    init(TREE, A, 1, 0, N-1);
    
    int x, y, a, b;
    int tmp;
    for(int q=0; q<Q; q++){
        cin >> x >> y >> a >> b;
        if(x>y){
            tmp = x;
            x = y;
            y = tmp;
        }
        cout << sum(TREE, 1, 0, N-1, x-1, y-1) << "\n";
        long long diff = b - A[a-1];
        update(TREE, 1, 0, N-1, a-1, diff);
        A[a-1] = b;
    }
    
    return 0;
    
}

