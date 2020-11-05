// https://www.acmicpc.net/problem/3019
// 테트리스
// Written in C++ langs
// 2020. 11. 05.
// Wizley

#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<tuple>
#include<string.h>

using namespace std;

vector<int> height;
int C, P;

int simulate(){
    int result = 0;
    switch(P){
        case 1:
            result += C; // 세로로 세우는건 어디든 가능
            
            for(int i=0; i<height.size()-3; i++){
                bool flag = true;
                for(int j=0; j<4; j++){
                    if(height[i+j] != height[i]) flag = false;
                }
                if(flag) result++;
            }
            break;
        case 2:
            for(int i=0; i<height.size()-1; i++){
                bool flag = true;
                for(int j=0; j<2; j++){
                    if(height[i+j] != height[i]) flag = false;
                }
                if(flag) result++;
            }
            break;
        case 3:
            for(int i=0; i<height.size()-2; i++){
                bool flag = true;
                for(int j=0; j<2; j++){
                    if(height[i+j] != height[i]) flag = false;
                }
                if(flag){
                    if(height[i+2] == height[i]+1) result++;
                }
            }
            for(int i=0; i<height.size()-1; i++){
                if(height[i]-height[i+1] == 1) result++;
            }
            break;
        case 4:
            for(int i=0; i<height.size()-2; i++){
                bool flag = true;
                for(int j=1; j<=2; j++){
                    if(height[i+j] != height[i]-1) flag = false;
                }
                if(flag) result++;
            }
            for(int i=0; i<height.size()-1; i++){
                if(height[i+1]-height[i] == 1) result++;
            }
            break;
        case 5:
            for(int i=0; i<height.size()-2; i++){
                bool flag = true;
                for(int j=0; j<3; j++){
                    if(height[i] != height[i+j]) flag = false;
                }
                if(flag) result++;
            
                flag = true;
                for(int j=0; j<3; j++){
                    if(j%2) {
                        if(height[i]-1 != height[i+j]) flag = false;
                    }
                    else {
                        if(height[i] != height[i+j]) flag = false;
                    }
                }
                if(flag) result++;
            }
             
            for(int i=0; i<height.size()-1; i++){
                if(height[i]+1 == height[i+1]) result++;
                if(height[i]-1 == height[i+1]) result++;
            }
            
            break;
        case 6:
            for(int i=0; i<height.size()-2; i++){
                if(height[i]==height[i+1] && height[i]==height[i+2]) result++;
                if(height[i+1]==height[i+2] && height[i]==height[i+2]-1) result++;
            }
            for(int i=0; i<height.size()-1; i++){
                if(height[i]==height[i+1]) result++;
                if(height[i]==height[i+1]+2) result++;
            }
            break;
        case 7:
            for(int i=0; i<height.size()-2; i++){
                if(height[i]==height[i+1] && height[i]==height[i+2]) result++;
                if(height[i]==height[i+1] && height[i]-1==(height[i+2])) result++;
            }
            for(int i=0; i<height.size()-1; i++){
                if(height[i]==height[i+1]) result++;
                if(height[i]==height[i+1]-2) result++;
            }
            break;
    }
    
    return result;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> C >> P;
    height.resize(C);
    
    for(int c=0; c<C; c++){
        cin >> height[c];
    }
    
    cout << simulate() << "\n";
    
    return 0;
}

