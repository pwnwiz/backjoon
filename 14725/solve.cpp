// https://www.acmicpc.net/problem/14725
// 개미굴
// Written in C++ langs
// 2020. 08. 26.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node{
    int depth;
    vector<Node> child;
    string name;
    
    Node(string n, int d){
        name = n;
        depth = d;
    }
};

bool compare(const Node &a, const Node &b){
    return a.name < b.name;
}

void print(Node *root){
    sort(root->child.begin(), root->child.end(), compare);
    
    for(auto r : root->child){
        if(r.depth > 1){
            for(int i=0; i<r.depth-1; i++){
                cout << "--";
            }
        }
        cout << r.name << "\n";
        
        print(&r);
    }
    
}

int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> N;
    
    int t;
    
    Node *root = new Node("root", 0);
    
    for(int i=0; i<N; i++){
        cin >> t;
        
        int depth = 1;
        
        Node *cur = root;
        Node *found = NULL;
        
        string name;
        for(int j=0; j<t; j++){
            cin >> name;
            
            for(auto &c : cur->child){
                if(c.name == name){
                    found = &c;
                }
            }
            
            if(found == NULL){
                Node *pos = new Node(name, depth);
                cur->child.push_back(*pos);
                cur = &cur->child.back();
            } else {
                cur = found;
                found = NULL;
            }
            
            depth++;
        }
    }
    
    print(root);
    
    return 0;
}

