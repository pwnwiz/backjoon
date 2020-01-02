// https://www.acmicpc.net/problem/16288
// Passport Control
// Written in C++ langs
// 2020. 01. 02.
// Wizley

#include <iostream>
#include <queue>

using namespace std;
queue<int> BOOTH[101];

int main(){
    bool flag = false;
    int n, boothNumber;
    int queue[101]={0,};
    
    scanf("%d %d", &n, &boothNumber);
    for(int i=0; i<n; i++) scanf("%d", &queue[i]);
    
    for(int i=0; i<n; i++){
        flag = false;
        for(int j=0; j<boothNumber; j++){
            if(BOOTH[j].empty()){
                BOOTH[j].push(queue[i]);
                flag = true;
                break;
            }
            else if(queue[i] > BOOTH[j].back()){
                BOOTH[j].push(queue[i]);
                flag = true;
                break;
            }
        }
        if(!flag){
            printf("NO\n");
            exit(0);
        }
    }
    printf("YES\n");
}

