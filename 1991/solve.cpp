// https://www.acmicpc.net/problem/1991
// 트리 순회
// Written in C++ langs
// 2020. 02. 25.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>

using namespace std;

typedef struct NODE{
    char NAME;
    struct NODE *left;
    struct NODE *right;
}NODE;

NODE *ROOT;

NODE* allocateNODE(char name, NODE* l, NODE* r){
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if(!newNode) return NULL;
    
    newNode->NAME=name;
    newNode->left=l;
    newNode->right=r;
    return newNode;
}

NODE* findNODE(NODE *node, char name){
    if(!node) return NULL;
    if(node->NAME == name)
        return node;
    
    else{
        NODE *cur = findNODE(node->left, name);
        if(cur) return cur;
        cur = findNODE(node->right, name);
        return cur;
    }
    
    return NULL;
}

void insertNODE(NODE *node, char name, char l, char r){
    l == '.' ? node->left = NULL : node->left = allocateNODE(l, NULL, NULL);
    r == '.' ? node->right = NULL : node->right = allocateNODE(r, NULL, NULL);
}

void preOrder(NODE *node){
    NODE *cur = node;
    if(!cur) return;
    cout << cur->NAME;
    
    if(cur->left != NULL)
        preOrder(cur->left);
    
    if(cur->right != NULL)
        preOrder(cur->right);
}

void inOrder(NODE *node){
    NODE *cur = node;
    
    if(cur->left != NULL){
        inOrder(cur->left);
    }
    
    cout << cur->NAME;
    
    if(cur->right != NULL){
        inOrder(cur->right);
    }
}

void postOrder(NODE *node){
    NODE *cur = node;
    
    if(cur->left != NULL){
        postOrder(cur->left);
    }
    
    if(cur->right != NULL){
        postOrder(cur->right);
    }
    
    cout << cur->NAME;
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int count;
    char target, left, right;
    cin >> count;

    for(int i=0; i<count; i++){
        cin >> target >> left >> right;
        
        if(ROOT == NULL){
            ROOT = allocateNODE(target, NULL, NULL);
            insertNODE(ROOT, target, left, right);
        }
        else{
            NODE *tmp = findNODE(ROOT, target);
            insertNODE(tmp, target, left, right);
        }
    }
    
    preOrder(ROOT);
    cout << "\n";
    inOrder(ROOT);
    cout << "\n";
    postOrder(ROOT);
    cout << "\n";
    
    return 0;
    
}

