// https://www.acmicpc.net/problem/2212
// 센서
// Written in C++ langs
// 2020. 06. 04.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    vector<int> sensor;
    
    int in;
    for(int n=0; n<N; n++){
        cin >> in;
        sensor.push_back(in);
    }
    
    sort(sensor.begin(), sensor.end(), less<>());
    
    vector<int> distance;
    for(int n=0; n<N-1; n++){
        distance.push_back(sensor[n+1] - sensor[n]);
    }
    
    sort(distance.begin(), distance.end(), greater<>());
    
    for(int k=0; k<K-1; k++){
        if(distance.empty()) break;
        distance.erase(distance.begin());
    }
    
    int result = 0;
    for(auto s : distance){
        result += s;
    }
    cout << result << "\n";
    
    return 0;
}

