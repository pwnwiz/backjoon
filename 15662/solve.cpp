// https://www.acmicpc.net/problem/15662
// 톱니바퀴 (2)
// Written in C++ langs
// 2020. 05. 19.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N;
int C;
vector<deque<char>> WHEEL;
vector<pair<int,int>> COMMAND;

void simulation(){
    for(int i=0; i<COMMAND.size(); i++){
        vector<pair<int,int>> rotate;

        int index = COMMAND[i].first;
        int dir = COMMAND[i].second;
        
        rotate.push_back(make_pair(index, dir));
        
        int n_dir = dir;
        int c_idx = index;

        // 1 -> 2 -> 3 ... -> N
        for(int idx=index+1; idx<=N; idx++){
            n_dir = n_dir * -1;
            if(WHEEL[c_idx][2] == WHEEL[idx][6]) break;

            c_idx = idx;
            rotate.push_back(make_pair(idx, n_dir));

        }

        n_dir = dir;
        c_idx = index;

        // 5 -> 4 -> 3 ... -> 1
        for(int idx=index-1; idx>=1; idx--){
            n_dir = n_dir * -1;
            if(WHEEL[c_idx][6] == WHEEL[idx][2]) break;

            c_idx = idx;
            rotate.push_back(make_pair(idx, n_dir));
        }

        for(int i=0; i<rotate.size(); i++){
            int no = rotate[i].first;
            int d = rotate[i].second;

            if(d == -1){
                int tmp = WHEEL[no].front();
                WHEEL[no].pop_front();
                WHEEL[no].push_back(tmp);
            } else {
                int tmp = WHEEL[no].back();
                WHEEL[no].pop_back();
                WHEEL[no].push_front(tmp);
            }
        }
    }

    int cnt = 0;
    for(int i=1; i<=N; i++){
        if(WHEEL[i][0] == '1') cnt++;
    }

    cout << cnt << "\n";

}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    WHEEL.resize(N+1);

    char t;
    for(int i=1; i<=N; i++){
        for(int j=0; j<8; j++){
            cin >> t;
            WHEEL[i].push_back(t);
        }
    }

    cin >> C;
    int a, b;
    for(int i=0; i<C; i++){
        cin >> a >> b;
        COMMAND.push_back(make_pair(a,b));
    }

    simulation();

}

