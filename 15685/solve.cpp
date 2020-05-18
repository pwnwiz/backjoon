// https://www.acmicpc.net/problem/15685
// 드래곤 커브
// Written in C++ langs
// 2020. 05. 18.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int N;
bool MAP[101][101] = {0,};

void make_dragon_curve(int x, int y, int dir, int generation){
    vector<int> a;
    vector<int> b;
    
    a.push_back(dir);
    
    for(int g=0; g<generation; g++){
        b = a;
        reverse(b.begin(), b.end());
        
        for(int i=0; i<b.size(); i++){
            b[i] += 1;
            if(b[i] > 3) b[i] = 0;
            a.push_back(b[i]);
        }
    }
    
    int nx = x;
    int ny = y;
    MAP[ny][nx] = true;
    
    for(int i=0; i<a.size(); i++){
        switch(a[i]){
            case 0:
                nx++;
                break;
            case 1:
                ny--;
                break;
            case 2:
                nx--;
                break;
            case 3:
                ny++;
                break;
        }
        
        if(nx<0 || ny<0 || nx>100 || ny>100){
            return;
        }
        
        MAP[ny][nx] = true;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    int x, y, d, g;
    for(int i=0; i<N; i++){
        cin >> x >> y >> d >> g;
        make_dragon_curve(x, y, d, g);
    }
    
    int rect = 0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(MAP[i][j] && MAP[i+1][j] && MAP[i][j+1] && MAP[i+1][j+1]){
                rect++;
            }
        }
    }
    
    cout << rect << "\n";
    
    return 0;
    
    
}

