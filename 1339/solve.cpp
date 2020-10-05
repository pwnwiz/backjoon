// https://www.acmicpc.net/problem/1339
// 단어 수학
// Written in C++ langs
// 2020. 10. 05.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <set>

using namespace std;

vector<string> v;
long long MAX_V = LLONG_MIN;
int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<char> alpha;
    set<char> s;

    cin >> N;

    string input;
    for(int i=0; i<N; i++){
        cin >> input;

        for(auto w : input){
            s.insert(w);
        }

        v.push_back(input);
    }

    for(auto sw : s){
        alpha.push_back(sw);
    }

    sort(alpha.begin(), alpha.end());

    do{
        int alphabet[27] = {0,};

        int cno = 9;
        for(int i=0; i<alpha.size(); i++){
            alphabet[alpha[i]-'A'] = cno--;
        }

        long long sum = 0;

        for(auto vv : v){
            int s = 0;

            int digit = 1;
            for(int i=vv.size()-1; i>=0; i--){
                s += alphabet[vv[i]-'A']*digit;
                digit *= 10;
            }
            sum += s;
        }

        MAX_V = max(MAX_V, sum);
    }while(next_permutation(alpha.begin(), alpha.end()));

    cout << MAX_V << "\n";

    return 0;
}


