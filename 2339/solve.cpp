// https://www.acmicpc.net/problem/2339
// 석판 자르기
// Written in C++ langs
// 2020. 03. 30.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

enum {
    IMPURITY = 1,
    JEWEL = 2,
    HORIZONTAL = 3,
    VERTICAL = 4,
};

int MAP[20][20]={0,};

int N;

bool is_valid(int x1, int y1, int x2, int y2){
    int jewels = 0;
    int impurities = 0;
    for(int x=x1; x<x2; x++){
        for(int y=y1; y<y2; y++){
            if(MAP[x][y] == IMPURITY){
                impurities++;
            }
            else if(MAP[x][y] == JEWEL){
                jewels++;
            }
        }
    }
    
    if(jewels == 1 && impurities == 0){
        return true;
    }
    return false;
}

bool is_valid(int x1, int x2, int y1, int y2, int direction){
    if(direction == HORIZONTAL){
        for(int j=y1; j<y2; j++){
            if(MAP[x1][j] == JEWEL){
                return false;
            }
        }
    }
    if(direction == VERTICAL){
        for(int j=x1; j<x2; j++){
            if(MAP[j][y1] == JEWEL){
                return false;
            }
        }
    }
    return true;
}

int dc(int x1, int y1, int x2, int y2, int direction){
    int total = 0;
    int jewels = 0;
    vector<pair<int,int>> impurities;
    for(int x=x1; x<x2; x++){
        for(int y=y1; y<y2; y++){
            if(MAP[x][y] == IMPURITY){
                impurities.push_back(make_pair(x,y));
            }
            else if(MAP[x][y] == JEWEL){
                jewels ++;
            }
        }
    }
    if(jewels == 1 && impurities.size() == 0) return 1;
    if(jewels == 0 || impurities.size() == 0) return 0;
   
    for(int i=0; i<impurities.size(); i++){
        int cur_x = impurities[i].first;
        int cur_y = impurities[i].second;
        
        if(direction == HORIZONTAL){
            if(is_valid(cur_x, cur_x, y1, y2, VERTICAL)){
                total += dc(x1, y1, x2, cur_y, VERTICAL) * dc(x1, cur_y+1, x2, y2, VERTICAL);
            }
        }
        
        else{
            if(is_valid(x1, x2, cur_y, cur_y, HORIZONTAL)){
                total += dc(x1, y1, cur_x, y2, HORIZONTAL) * dc(cur_x+1, y1, x2, y2, HORIZONTAL);
            }
        }
    }
    
    return total;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> MAP[i][j];
        }
    }
    
    int result = dc(0,0,N,N,HORIZONTAL) + dc(0,0,N,N,VERTICAL);
    (result == 0) ? cout << "-1\n" : cout << result << "\n";
    
    return 0;
    
}

