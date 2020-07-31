// https://www.acmicpc.net/problem/10448
// 유레카 이론
// Written in C++ langs
// 2020. 07. 30.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool triangle[1001] = {};
long long N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    int cur = 0;
    int pos = 1;
    while(cur<=1000){
        cur += pos;
        triangle[cur] = true;
        pos += 1;
    }

    vector<int> numbers;
    
    int input;
    for(long long i=0; i<N; i++){
        cin >> input;
        numbers.push_back(input);
    }
    
    for(int i=0; i<numbers.size(); i++){
        int endn = numbers[i];
        
        bool flag = false;
        for(int j=1; j<endn; j++){
            if(!triangle[j]) continue;
            
            for(int k=1; k<endn; k++){
                if(!triangle[k]) continue;
                
                for(int l=1; l<endn; l++){
                    if(!triangle[l]) continue;
                    
                    if(j+k+l==endn){
                        flag = true;
                        break;
                    }
                }
                
            }
        }
        
        flag ? cout << "1\n" : cout << "0\n";
        
    }
    
    
    return 0;
    
}

