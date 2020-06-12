// https://www.acmicpc.net/problem/2170
// 선 긋기
// Written in C++ langs
// 2020. 06. 12.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int,int>> line;
int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    int f, t;
    for(int i=0; i<N; i++){
        cin >> f >> t;
        if(f>t) swap(f,t);
        line.push_back(make_pair(f,t));
    }
    
    sort(line.begin(), line.end());

    int start = line[0].first;
    int end = line[0].second;
    
    int result = 0;
    for(int l=1; l<N; l++){
        int cur_s = line[l].first;
        int cur_e = line[l].second;
        
        // 범위 내에 시작지점에 존재할 경우
        if(cur_s <= end){
            end = max(end, cur_e);
        }
        
        // 범위 밖일 경우
        else {
            result += end - start;
            start = cur_s;
            end = cur_e;
        }
    }
    
    result += end - start;
    
    cout << result << "\n";
    
    return 0;
    
}

