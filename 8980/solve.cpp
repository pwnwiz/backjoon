// https://www.acmicpc.net/problem/8980
// 택배
// Written in C++ langs
// 2020. 06. 04.
// Wizley

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<tuple<int, int, int>> BOX;
int N, C, M;

bool compare(const tuple<int,int,int> &A, const tuple<int,int,int> &B){
    if(get<1>(A) < get<1>(B)) return true;
    else if((get<1>(A) == get<1>(B)) && (get<0>(A) > get<0>(B))) return true;
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> C;
    cin >> M;
    
    int a, b, c;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        BOX.push_back({a,b,c});
    }
    
    sort(BOX.begin(), BOX.end(), compare);
    
    vector<int> weight(N+1);
    fill(weight.begin(), weight.end(), C);

    int carried = 0;
    for(int i=0; i<BOX.size(); i++){
        int min_val = INT_MAX;
        
        int s = get<0>(BOX[i]);
        int e = get<1>(BOX[i]);
        int w = get<2>(BOX[i]);
        
        for(int pos=s; pos<e; pos++){
            min_val = min(min_val, weight[pos]);
        }
        
        if(w <= min_val){
            for(int pos=s; pos<e; pos++){
                weight[pos] -= w;
            }
            carried += w;
        }
        else {
            if(min_val == 0) continue;
            for(int pos=s; pos<e; pos++){
                weight[pos] -= min_val;
            }
            carried += min_val;
        }
    }
    
    cout << carried << "\n";
        
    return 0;
    
}

