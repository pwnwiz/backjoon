// https://www.acmicpc.net/problem/15686
// 치킨 배달
// Written in C++ langs
// 2020. 07. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int MAP[50][50];
int N, M;

int RESULT = 987654321;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    vector<pair<int,int>> store;
    vector<pair<int,int>> house;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 2){
                store.push_back(make_pair(i,j));
            } else if(MAP[i][j] == 1){
                house.push_back(make_pair(i,j));
            }
        }
    }
     
    vector<int> permute;
    for(int i=0; i<store.size(); i++){
        if(permute.size() < M) permute.push_back(1);
        else permute.push_back(0);
    }
    sort(permute.begin(), permute.end());
    
    do{
        int total_dist = 0;
        for(int i=0; i<house.size(); i++){
            int dist = 987654321;
            
            for(int j=0; j<store.size(); j++){
                if(permute[j]){
                    dist = min(dist, abs(store[j].first-house[i].first)+abs(store[j].second-house[i].second));
                }
            }
            total_dist += dist;
        }
        RESULT = min(RESULT, total_dist);
    } while(next_permutation(permute.begin(), permute.end()));
    
    cout << RESULT << "\n";
    
    return 0;
    
}

