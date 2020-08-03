// https://www.acmicpc.net/problem/2981
// 검문
// Written in C++ langs
// 2020. 08. 03.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N;

int getGCD(int x, int y){
    if(x<y) swap(x,y);
    
    if(y == 0) return x;
    else return getGCD(y, x%y);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<int> arr;
    set<int> common_factor;
    
    int input;
    for(int i=0; i<N; i++){
        cin >> input;
        arr.push_back(input);
    }
    
    sort(arr.begin(), arr.end());
    
    // Ax % M = Ax - (Ax/M) * M
    // 5 % 3 = 5 - (1)*3
    // Ay % M = Ay - (Ay/M) * M
    // 7 % 3 = 7 - (2)*3
    // hence
    // if Ax % M == Ay % M
    // Ax - (Ax/M) * M == Ay - (Ay/M) * M
    // Ax - Ay = (Ax/m - Ay/M) * M
    // hence
    // A[n-1] - A[n] = (A[n-1]/M - A[n]/M) * M
    int gcd = arr[1] - arr[0];
    for(int i=2; i<arr.size(); i++){
        gcd = getGCD(gcd, arr[i]-arr[i-1]);
    }

    for(int i=2; i*i<=gcd; i++){
        if(gcd % i == 0){
            // if
            // gcd == 10
            // i == 2
            // 2 and 5 is common_factor
            common_factor.insert(i);
            common_factor.insert(gcd/i);
        }
    }
    common_factor.insert(gcd);
    
    for(auto factor : common_factor){
        cout << factor << " ";
    }
    
    return 0;
}

