// https://www.acmicpc.net/problem/2094
// 강수량
// Written in C++ langs
// 2020. 05. 26.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<pair<int,int>> YEAR;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    int y, d, y2;
    for(int n=0; n<N; n++){
        cin >> y >> d;
        YEAR.push_back(make_pair(y,d));
    }
    
    cin >> M;
    for(int m=0; m<M; m++){
        bool maybe = false;
        
        int from = -1;
        int from_rained = -1;
        
        int to = -1;
        int to_rained = -1;
        
        int max_rained = -1;
        int year_cnt = 0;
        cin >> y >> y2;
        
        for(int i=0; i<YEAR.size(); i++){
            if(YEAR[i].first < y) continue;
            
            // 시작 지점
            else if(YEAR[i].first == y){
                from = i;
                from_rained = YEAR[i].second;
            }
            
            // 시작 지점 <-> 도착 지점
            else if(YEAR[i].first > y && YEAR[i].first < y2){
                max_rained = max(max_rained, YEAR[i].second);
                year_cnt++;
            }
            
            // 도착 지점
            else if(YEAR[i].first == y2){
                to = i;
                to_rained = YEAR[i].second;
            }
            
            // 그 외
            else{
                break;
            }
        }

        // 시작지점과 도착지점 사이에 특정 지점의 값이 없는 경우
        int years = y2 - y - 1;
        if(years > year_cnt){
            maybe = true;
        }

       // 시작 지점보다 중간 강수량이 큰 경우
       if(from != -1 && max_rained >= from_rained){
           cout << "false\n";
           continue;
       }

       // 도착 지점보다 중간 강수량이 큰 경우
       if(to != -1 && max_rained >= to_rained){
           cout << "false\n";
           continue;
       }

       // 시작 지점이 도착 지점보다 강수량이 큰 경우
       if(from != -1 && to != -1 && from_rained < to_rained){
           cout << "false\n";
           continue;
       }

       // 시작 지점과 도착 지점이 1년 차이인 경우
       if(from != -1 && to!= -1 && y == y2-1){
           cout << "true\n";
           continue;
       }

       // 시작 지점이 없는데 도착 지점과 1년 차이인 경우
       if(from == -1 && y == y2-1){
           cout << "maybe\n";
           continue;
       }

       // 도착 지점이 없는데 시작 지점과 1년 차이인 경우
       if(to == -1 && y == y2-1){
           cout << "maybe\n";
           continue;
       }

       // 시작 지점과 도착 지점이 1년 차이인데 모르는 경우
       if(from == -1 && to == -1 && y == y2-1){
           cout << "maybe\n";
           continue;
       }

       // 시작 지점 또는 도착 지점을 모를 경우
       if(from == -1 || to == -1){
           cout << "maybe\n";
           continue;
       }

       // 중간의 특정 지점을 모르는 경우
       if(maybe){
           cout << "maybe\n";
           continue;
       }

        cout << "true\n";

    }
    
    return 0;
    
}


