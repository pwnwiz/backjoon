// https://www.acmicpc.net/problem/17875
// Fantasy Draft
// Written in C++ langs
// 2020. 06. 08.
// Wizley

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string.h>

using namespace std;

int TEAM, TEAM_COUNT;
int TOTAL_PLAYER;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> TEAM >> TEAM_COUNT;
    
    vector<queue<string>> team(TEAM);
    vector<vector<string>> draft(TEAM);
    team.resize(TEAM);
    draft.resize(TEAM);
    
    int choice_cnt;
    for(int i=0; i<TEAM; i++){
        cin >> choice_cnt;
        
        for(int j=0; j<choice_cnt; j++){
            string player;
            cin >> player;
            team[i].push(player);
        }
    }
    
    map<string, int> rank;
    map<int, string> status;
    
    cin >> TOTAL_PLAYER;
    
    for(int i=0; i<TOTAL_PLAYER; i++){
        string player;
        cin >> player;
        
        // to get rank by player_name use rank
        // to get player name by rank use status
        rank[player] = i;
        status[i] = player;
    }
    
    for(int i=0; i<TEAM_COUNT; i++){
        for(int j=0; j<TEAM; j++){
            if(draft[j].size() < TEAM_COUNT){
                
                bool flag = false;
                
                // if preferred player is available get those player first
                while(!flag && !team[j].empty()){
                    string current_player = team[j].front();
                    team[j].pop();
                    
                    int pos = rank[current_player];
                    
                    if(status.count(pos) > 0){
                        draft[j].push_back(current_player);
                        status.erase(pos);
                        
                        flag = true;
                        break;
                    }
                }
                
                // if preferred player is not available get highest ranked player
                if(!flag){
                    string current_player = status.begin()->second;
                    draft[j].push_back(current_player);
                    status.erase(rank[current_player]);
                }
            }
        }
    }
    
    for(int i=0; i<TEAM; i++){
        for(int j=0; j<draft[i].size(); j++){
            cout << draft[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
    
}

