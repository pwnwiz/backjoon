// https://www.acmicpc.net/problem/2871
// 아름다운 단어
// Written in C++ langs
// 2020. 06. 03.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>
#include <string.h>

using namespace std;

int N;
string WORD;

vector<pair<char, int>> V;
vector<pair<char, int>> O;
vector<bool> USED;

string HEEWON;
string SANGGUEN;

bool compare(const pair<char, int> &A, const pair<char, int> &B){
    if(A.first < B.first){
        return true;
    }
    else if (A.first == B.first){
        if(A.second > B.second){
            return true;
        }
    }
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    USED.resize(N+1);
    
    char in;
    for(int i=0; i<N; i++){
        cin >> in;
        O.push_back(make_pair(in, i));
    }
    
    V = O;
    sort(V.begin(), V.end(), compare);

    bool heewon_turn = false;
    int heewon_pos = 0;
    int sanggeun_pos = N-1;
    
    for(int i=0; i<O.size(); i++){
        if(!heewon_turn){
            while(USED[sanggeun_pos]){
                sanggeun_pos--;
            }
            
            USED[sanggeun_pos] = true;
            SANGGUEN.insert(SANGGUEN.end(), O[sanggeun_pos].first);
            heewon_turn = true;
        }
        else {
            while(USED[V[heewon_pos].second]){
                heewon_pos++;
            }

            USED[V[heewon_pos].second] = true;
            HEEWON.insert(HEEWON.end(), V[heewon_pos].first);
            
            heewon_turn = false;
        }
    }
    
    if(SANGGUEN<=HEEWON){
        cout << "NE\n";
    } else {
        cout << "DA\n";
    }
    
    cout << HEEWON << "\n";

}

