// https://www.acmicpc.net/problem/13460
// 구슬 탈출 2
// Written in C++ langs
// 2020. 07. 29.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

char MAP[10][10];
int N, M;

pair<int,int> RED;
pair<int,int> BLUE;
pair<int,int> EXIT;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int RESULT = 987654321;

void bfs(){
    // RED, BLUE, COUNT
    queue<tuple<pair<int,int>, pair<int,int>, int>> que;
    que.push({RED, BLUE, 0});
    
    while(!que.empty()){
        auto red = get<0>(que.front());
        auto blue = get<1>(que.front());
        auto count = get<2>(que.front());
        que.pop();

        if(count >= 10 || count > RESULT) continue;
        
        for(int i=0; i<4; i++){
            int nx = red.first + dx[i];
            int ny = red.second + dy[i];
            
            int blue_meets_red = 0;
            int red_meets_blue = 0;
            int red_meets_exit = 0;
            int blue_meets_exit = 0;
            
            int red_move = 0;
            int blue_move = 0;
                        
            // RED 이동
            while(MAP[nx][ny] != '#' && nx>=0 && ny>=0 && nx<N && ny<M){
                red_move ++;
                
                // BLUE를 만날 경우
                if(nx == blue.first && ny == blue.second){
                    red_meets_blue = red_move;
                }
                // EXIT를 만날 경우
                if(nx == EXIT.first && ny == EXIT.second){
                    red_meets_exit = red_move;
                }
                nx += dx[i];
                ny += dy[i];
            }
        
            // BLUE 이동
            nx = blue.first + dx[i];
            ny = blue.second + dy[i];
            while(MAP[nx][ny] != '#' && nx>=0 && ny>=0 && nx<N && ny<M){
                blue_move ++;
                
                // RED를 만날 경우
                if(nx == red.first && ny == red.second){
                    blue_meets_red = blue_move;
                }
                
                // EXIT를 만날 경우
                if(nx == EXIT.first && ny == EXIT.second){
                    blue_meets_exit = blue_move;
                }
                
                nx += dx[i];
                ny += dy[i];
            }
            
            // RED와 BLUE가 같은 라인에 있지 않은 경우
            if(!red_meets_blue && !blue_meets_red){
                
                // RED가 EXIT를 만난 경우
                if(red_meets_exit){
                    RESULT = min(RESULT, count+1);
                }
        
                else {
                    // BLUE가 EXIT를 만나지 않은 경우
                    if(!blue_meets_exit){
                        auto next_red = make_pair(red.first + dx[i]*red_move, red.second + dy[i]*red_move);
                        auto next_blue = make_pair(blue.first + dx[i]*blue_move, blue.second + dy[i]*blue_move);
                        que.push({next_red, next_blue, count+1});
                    }
                }
            }
            
            // RED와 BLUE가 같은 선상에 있는 경우
            // BLUE가 앞서는 경우
            else if(red_meets_blue){
                // EXIT를 BLUE보다 먼저 만나는 경우
                if(red_meets_exit){
                    if(red_meets_exit < red_meets_blue){
                        RESULT = min(RESULT, count+1);
                    }
                }
                // BLUE를 먼저 만나는 경우 BLUE가 항상 앞에 위치함
                else {
                    auto next_red = make_pair(red.first + dx[i]*(red_move-1), red.second + dy[i]*(red_move-1));
                    auto next_blue = make_pair(blue.first + dx[i]*blue_move, blue.second + dy[i]*blue_move);
                    que.push({next_red, next_blue, count+1});
                }
            }
        
            // RED가 앞서는 경우
            else {
                // RED가 EXIT를 만나면 BLUE도 EXIT를 만남
                if(!red_meets_exit){
                    auto next_red = make_pair(red.first + dx[i]*red_move, red.second + dy[i]*red_move);
                    auto next_blue = make_pair(blue.first + dx[i]*(blue_move-1), blue.second + dy[i]*(blue_move-1));
                    que.push({next_red, next_blue, count+1});
                }
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
            
            if(MAP[i][j] == 'R'){
                MAP[i][j] = '.';
                RED = make_pair(i,j);
            } else if(MAP[i][j] == 'B'){
                MAP[i][j] = '.';
                BLUE = make_pair(i,j);
            } else if(MAP[i][j] == 'O'){
                MAP[i][j] = '.';
                EXIT = make_pair(i,j);
            }
        }
    }
    
    
    bfs();
    
    if(RESULT == 987654321){
        cout << "-1\n";
    } else {
        cout << RESULT << "\n";
    }
  
    return 0;
    
}

