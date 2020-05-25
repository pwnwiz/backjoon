// https://www.acmicpc.net/problem/5639
// 이진 검색 트리
// Written in C++ langs
// 2020. 05. 25.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Node{
    int elem;
    Node* left;
    Node* right;
    
    Node(int elem, Node* l, Node* r){
        this->elem = elem;
        this->left = l;
        this->right = r;
    };
}Node;

Node* ROOT = NULL;

Node* searchNode(int e){
    Node *cur = ROOT;
    
    while(cur){
        if(cur->elem > e && cur->left){
            cur = cur->left;
        }
        else if(cur->elem < e && cur->right) {
            cur = cur->right;
        }
        else{
            break;
        }
    }
    
    return cur;
}

void preOrder(Node *cur){
    if(!cur) return;
    cout << cur->elem << "\n";
    if(cur->left) preOrder(cur->left);
    if(cur->right) preOrder(cur->right);
}

void inOrder(Node *cur){
    if(!cur) return;
    if(cur->left) inOrder(cur->left);
    cout << cur->elem << "\n";
    if(cur->right) inOrder(cur->right);
}

void postOrder(Node *cur){
    if(!cur) return;
    if(cur->left) postOrder(cur->left);
    if(cur->right) postOrder(cur->right);
    cout << cur->elem << "\n";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int e;
    
    while(cin >> e){
        if(!ROOT){
            ROOT = new Node(e, NULL, NULL);
        }
        
        else {
            Node* found = searchNode(e);
            // left
            if(found->elem > e){
                Node *newNode = new Node(e, NULL, NULL);
                found->left = newNode;
            }
            // right
            else{
                Node *newNode = new Node(e, NULL, NULL);
                found->right = newNode;
            }
        }
    }
    
    postOrder(ROOT);
    
    return 0;
    
}

