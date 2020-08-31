// https://www.acmicpc.net/problem/11437
// LCA
// Written in C++ langs
// 2020. 08. 31.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node{
    int no;
    int depth;
    
    vector<Node*> child;
    Node* parent = NULL;
    
    Node(int n){
        no = n;
    }
};

int N, M;

vector<Node*> nodes;
vector<vector<int>> edges;
vector<bool> visited;

void makeTree(int pos, int depth){
    visited[pos] = true;
    nodes[pos]->depth = depth;
    
    for(auto next: edges[pos]){
        if(visited[next]) continue;
        
        nodes[pos]->child.push_back(nodes[next]);
        nodes[next]->parent = nodes[pos];
        
        makeTree(next, depth+1);
    }
}

void lca(int a, int b){
    if(nodes[a]->depth < nodes[b]->depth) swap(a,b);
    
    while(nodes[a]->depth != nodes[b]->depth){
        a = nodes[a]->parent->no;
    }
    
    if(a == b){
        cout << a << "\n";
    }

    else {
        while(nodes[a]->no != nodes[b]->no){
            a = nodes[a]->parent->no;
            b = nodes[b]->parent->no;
        }
        cout << a << "\n";
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    nodes.resize(N+1);
    edges.resize(N+1);
    visited.resize(N+1);
    
    for(int i=1; i<=N; i++){
        nodes[i] = new Node(i);
    }
    
    int a, b;
    for(int i=1; i<N; i++){
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    makeTree(1,1);
    
    cin >> M;
    
    for(int i=0; i<M; i++){
        cin >> a >> b;
        lca(a,b);
    }
    
    return 0;
}

