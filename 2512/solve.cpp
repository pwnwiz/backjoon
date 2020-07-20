// https://www.acmicpc.net/problem/2512
// 예산
// Written in C++ langs
// 2020. 07. 20.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
long long P;

pair<int,int> MAXV = make_pair(0,0);

void bisect(vector<long long> &pr, long long l, long long r){
    
    while(l<=r){
        long long mid = (l+r)/2;
        
        long long v = 0;
        for(int i=0; i<N; i++){
            if(pr[i] >= mid){
                v += mid;
            } else {
                v += pr[i];
            }
        }
        
        if(v> P){
            r = mid-1;
        } else if(v == P){
            MAXV = make_pair(v, mid);
            return;
        } else {
            if(MAXV.first < v){
                MAXV = make_pair(v, mid);
            }
            l = mid+1;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<long long> pr;
        
    cin >> N;
    int in;
    
    for(int i=0; i<N; i++){
        cin >> in;
        pr.push_back(in);
    }
    sort(pr.begin(), pr.end());
    
    cin >> P;

    if(pr[0]*N == P){
        cout << pr[0] << "\n";
    } else if(pr[0]*N > P){
        bisect(pr, 1, pr[0]);
        cout << MAXV.second << "\n";
    } else {
        bisect(pr, pr[0], pr[N-1]);
        cout << MAXV.second << "\n";
    }

    return 0;
}

