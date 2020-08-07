// https://www.acmicpc.net/problem/1068
// 트리
// Written in C++ langs
// 2020. 08. 07.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct NODE{
    int name;
    NODE *parent;
    vector<int> child;
    
    NODE(int name, NODE *parent){
        this->name = name;
        this->parent = parent;
    }
};

int N, M;
vector<NODE> nodes;

int search(NODE *cur){
    
    int cnt = 0;
    if(cur->child.empty()){
        return 1;
    } else {
        for(auto c : cur->child){
            cnt += search(&nodes[c]);
        }
    }
    return cnt;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    NODE *root = NULL;
    
    for(int i=0; i<N; i++){
        nodes.push_back(NODE(i, NULL));
    }
    
    int input;
    for(int i=0; i<N; i++){
        cin >> input;
        
        if(input == -1){
            root = &nodes[i];
        } else {
            nodes[i].parent = &nodes[input];
            nodes[input].child.push_back(i);
        }
    }

    cin >> M;
    
    if(M == root->name){
        cout << "0\n";
        return 0;
    }
    
    for(int i=0; i<nodes[M].parent->child.size(); i++){
        if(nodes[nodes[M].parent->child[i]].name == M){
            nodes[M].parent->child.erase(nodes[M].parent->child.begin()+i);
            break;
        }
    }
    
    cout << search(root) << "\n";


    return 0;
    
}

