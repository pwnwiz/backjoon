// https://www.acmicpc.net/problem/3568
// iSharp
// Written in C++ langs
// 2020. 11. 04.
// Wizley

#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>
#include<sstream>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string input;
    getline(cin, input);
    
    vector<string> vtoken;
    string token;
    for(istringstream is(input); is>>token;){
        vtoken.push_back(token);
    }
    
    for(int i=1; i<vtoken.size(); i++){
        reverse(vtoken[i].begin(), vtoken[i].end());
        
        string var;
        string exp;
        for(int x=1; x<vtoken[i].size(); x++){
            if((vtoken[i][x] >='a' && vtoken[i][x] <= 'z') || (vtoken[i][x] >= 'A' && vtoken[i][x] <= 'Z')){
                var += vtoken[i][x];
            }
            else {
                if(vtoken[i][x] == '[') continue;
                if(vtoken[i][x] == ']') exp += '[';
                exp += vtoken[i][x];
            }
        }
        reverse(var.begin(), var.end());
        cout << vtoken[0] << exp << " " << var << ";\n";
    }
    
    return 0;
}

