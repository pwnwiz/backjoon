// https://www.acmicpc.net/problem/7568
// 덩치
// Written in C++ langs
// 2020. 07. 27.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<pair<int,int>> human;
    vector<int> result;

    cin >> N;
    
    int x, y;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        human.push_back(make_pair(x,y));
    }

    for(int i=0; i<human.size(); i++){
        int w = human[i].first;
        int h = human[i].second;
        
        int cnt = 0;
        
        for(int j=0; j<human.size(); j++){
            
            int nw = human[j].first;
            int nh = human[j].second;
            
            if(w < nw && h < nh){
                cnt ++;
            }
        }
        result.push_back(cnt+1);
    }
    
    for(auto r : result){
        cout << r << " ";
    }
    cout << "\n";
    
    return 0;
    
}

