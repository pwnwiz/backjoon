// https://www.acmicpc.net/problem/14425
// 문자열 집합
// Written in C++ langs
// 2020. 09. 01.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

struct TRIE {
    TRIE *children[27];
    bool terminal = false;
    
    TRIE() : terminal(false){
        memset(children, 0, sizeof(children));
    }
    
    ~TRIE(){
        for(int i=0; i<27; i++){
            if(children[i]) delete children[i];
        }
    }
    
    void insert(string &key, int pos){
        if(key[pos] == '\0') terminal = true;
        else {
            int next = key[pos] - 'a';
            
            if(children[next] == NULL){
                children[next] = new TRIE();
            }
            children[next]->insert(key, pos+1);
        }
    }
    
    bool find(string &key, int pos){
        if(key[pos] == '\0'){
            return terminal;
        }
        
        if(terminal == true){
            return false;
        }
        
        int next = key[pos] - 'a';
        
        if(children[next] == NULL) return false;
        
        return children[next]->find(key, pos+1);
    }
};

int N, M;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    TRIE *root = new TRIE();
    
    string in;
    for(int i=0; i<N; i++){
        cin >> in;
        root->insert(in, 0);
    }

    int cnt = 0;
    for(int j=0; j<M; j++){
        cin >> in;
        if(root->find(in, 0)){
            cnt++;
        }
    }
    
    cout << cnt << "\n";
  
    return 0;
    
}

