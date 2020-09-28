// https://www.acmicpc.net/problem/9613
// GCD 합
// Written in C++ langs
// 2020. 09. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T;

int gcd(int a, int b){
    while(a){
        int n = b % a;
        b = a;
        a = n;
    }
    return b;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    
    int n;
    for(int i=0; i<T; i++){
        cin >> n;
        
        vector<int> numbers(n);
        
        for(int j=0; j<n; j++){
            cin >> numbers[j];
        }
  
        sort(numbers.begin(), numbers.end());
        
        long long sum = 0;
        for(int x=0; x<numbers.size(); x++){
            
            for(int y=x+1; y<numbers.size(); y++){
                sum += gcd(numbers[x], numbers[y]);
            }
        }
        
        cout << sum << "\n";
        
        
    }
    
    return 0;
    
}

