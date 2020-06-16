// https://www.acmicpc.net/problem/3653
// 영화 수집
// Written in C++ langs
// 2020. 06. 16.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int T;
int N, M;

int init(vector<int> &tree, vector<int> &a, int node, int start, int end){
    if(start == end){
        return tree[node] = a[start];
    }
    return tree[node] = init(tree, a, node*2, start, (start+end)/2) + init(tree, a, node*2+1, (start+end)/2+1, end);
}

int sum(vector<int> &tree, int node, int start, int end, int l, int r){
    if(r < start || l > end) return 0;

    if(l<=start && end<=r){
        return tree[node];
    }

    return sum(tree, node*2, start, (start+end)/2, l, r) + sum(tree, node*2+1, (start+end)/2+1, end, l, r);
}

void update(vector<int> &tree, int node, int start, int end, int index, int diff){
    if(index<start || index>end) return;

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

    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N >> M;

        int h = ceil(log2(N+M));
        int tree_size = (1<<(h+1));

        vector<int> segment_tree(tree_size);
        vector<int> arr(N+M);

        for(int i=1; i<M; i++){
            arr[i] = 0;
        }

        for(int i=M; i<N+M; i++){
            arr[i] = 1;
        }

        init(segment_tree, arr, 1, 0, N+M-1);

        vector<int> range(N+1);
        for(int i=1; i<=N; i++){
            range[i] = M+i-1;
        }

        int no;
        int pos = M-1;
        for(int m=0; m<M; m++){
            cin >> no;

            cout << sum(segment_tree, 1, 0, N+M-1, 0, range[no]-1) << " ";

            update(segment_tree, 1, 0, N+M-1, range[no], -1);
            range[no] = pos--;
            update(segment_tree, 1, 0, N+M-1, range[no], 1);
        }
        cout << "\n";

    }

    return 0;

}

