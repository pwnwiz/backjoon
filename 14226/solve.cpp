// https://www.acmicpc.net/problem/14226
// 이모티콘
// Written in C++ langs
// 2020. 09. 29.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int S;

bool visited[1001][1001];
int simulate(){
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    visited[1][0] = true;
    pq.push({0, 1, 0});
    
    while(!pq.empty()){
        int timestamp = get<0>(pq.top());
        int emotion_cnt = get<1>(pq.top());
        int clipboard_cnt = get<2>(pq.top());
        pq.pop();
        
        if(emotion_cnt == S){
            return timestamp;
        }
        
        // 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
        if(clipboard_cnt < emotion_cnt) pq.push({timestamp+1, emotion_cnt, emotion_cnt});
        
        // 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
        if(!visited[emotion_cnt][clipboard_cnt] && clipboard_cnt+emotion_cnt<=1000 && clipboard_cnt){
            visited[emotion_cnt][clipboard_cnt] = true;
            pq.push({timestamp+1, emotion_cnt+clipboard_cnt, clipboard_cnt});
        }
        
        // 화면에 있는 이모티콘 중 하나를 삭제한다.
        if(!visited[emotion_cnt-1][clipboard_cnt] && emotion_cnt>2){
            visited[emotion_cnt-1][clipboard_cnt] = true;
            pq.push({timestamp+1, emotion_cnt-1, clipboard_cnt});
        }
    }
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> S;

    cout << simulate() << "\n";
    
    return 0;
    
}

