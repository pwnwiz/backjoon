// https://www.acmicpc.net/problem/5052
// 전화번호 목록
// Written in C++ langs
// 2020. 08. 04.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

const int NUMBER = 10;
struct TRIE {
    // 0 ~ 9
    TRIE* children[NUMBER];

    bool terminal = false;
    
    TRIE() : terminal(false){
        memset(children, 0, sizeof(children));
    }
    
    ~TRIE(){
        for(int i=0; i<NUMBER; i++){
            if(children[i]) delete children[i];
        }
    }
    
    void insert(string &key, int idx){
        if(key[idx] == '\0') terminal = true;
        else {
            int next = key[idx] - '0';
            
            if(children[next] == NULL){
                children[next] = new TRIE();
            }
            children[next]->insert(key, idx+1);
        }
    }
    
    bool find(string &key, int idx){
        // 글자가 마지막까지 도달한 경우
        if(key[idx] == '\0'){
            return true;
        }
        
        // 글자가 마지막까지 도달하지 못하였지만 해당 인덱스까지의 문자열이 존재하는 경우
        if(terminal == true){
            return false;
        }
        
        int next = key[idx] - '0';
        return children[next]->find(key, idx+1);
    }
};


int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    int M;
    for(int i=0; i<N; i++){
        cin >> M;
        
        TRIE *root = new TRIE();
        bool flag = false;
        
        vector<string> phone;
        
        string in;
        for(int j=0; j<M; j++){
            cin >> in;
            phone.push_back(in);
        }
        
        for(int j=0; j<phone.size(); j++){
            root->insert(phone[j], 0);
        }
        
        for(int j=0; j<phone.size(); j++){
            if(!root->find(phone[j], 0)){
                flag = true;
            }
        }
        
        flag? cout << "NO\n" : cout << "YES\n";
    }
    
    return 0;
}

