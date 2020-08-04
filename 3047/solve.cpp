// https://www.acmicpc.net/problem/3047
// ABC
// Written in C++ langs
// 2020. 08. 04.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> tmp;
    
    int inp;
    for(int i=0; i<3; i++){
        cin >> inp;
        tmp.push_back(inp);
    }
    
    sort(tmp.begin(), tmp.end());
    
    vector<pair<int,char>> ABC;
    
    ABC.push_back(make_pair(tmp[0], 'A'));
    ABC.push_back(make_pair(tmp[1], 'B'));
    ABC.push_back(make_pair(tmp[2], 'C'));

    string input;
    
    cin >> input;
    
    for(int i=0; i<input.size(); i++){
        for(auto v : ABC){
            if(v.second == input[i]){
                cout << v.first;
            }
        }
        if(i<2) cout << " ";
        else cout << "\n";
    }
    
   
    return 0;
}

