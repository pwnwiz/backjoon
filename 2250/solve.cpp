// https://www.acmicpc.net/problem/2250
// 트리의 높이와 너비
// Written in C++ langs
// 2020. 08. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int LEVEL[10001][2];
int N;

struct Node{
    int no;
    Node* left;
    Node* right;
    
    Node(int n){
        no = n;
        left = NULL;
        right = NULL;
    }
    
    Node(int n, Node *l, Node *r){
        no = n;
        left = l;
        right = r;
    }
};

Node* findNode(Node* root, int n){
    queue<Node*> que;
    que.push(root);
    
    while(!que.empty()){
        Node* cur = que.front();
        que.pop();
        
        if(cur->no == n){
            return cur;
        }
        
        if(cur->left != NULL) que.push(cur->left);
        if(cur->right != NULL) que.push(cur->right);
    }
    
    return NULL;
}

int MAX_LEVEL = 1;
int WIDTH = 1;
void Visit(Node *cur, int level){
    if(cur == NULL) return;

    Visit(cur->left, level+1);

    LEVEL[level][0] = min(LEVEL[level][0], WIDTH);
    LEVEL[level][1] = max(LEVEL[level][1], WIDTH);
    WIDTH++;
    
    MAX_LEVEL = max(MAX_LEVEL, level);
    
    Visit(cur->right, level+1);
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    vector<Node*> nodes(N+1);
    vector<bool> hasParent(N+1, false);

    Node* root = NULL;
    
    for(int i=1; i<=N; i++){
        nodes[i] = new Node(i);
    }
    
    int node, l, r;
    for(int i=0; i<N; i++){
        cin >> node >> l >> r;

        if(l != -1){
            nodes[node]->left = nodes[l];
            hasParent[l] = true;
        }
        if(r != -1){
            nodes[node]->right = nodes[r];
            hasParent[r] = true;
        }
    }
    
    for(int i=1; i<=N; i++){
        if(!hasParent[i]){
            root = nodes[i];
            break;
        }
    }
    
    for(int i=1; i<10001; i++){
        LEVEL[i][0] = 987654321;
    }
    
    Visit(root, 1);
    
    int maxl = 1;
    int maxv = 0;
    for(int i=1; i<=MAX_LEVEL; i++){
        int w = LEVEL[i][1] - LEVEL[i][0] + 1;
        
        if(maxv < w){
            maxv = w;
            maxl = i;
        }
    }
    
    cout << maxl << " " << maxv << "\n";
    
    return 0;

}

