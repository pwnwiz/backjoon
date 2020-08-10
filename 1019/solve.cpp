// https://www.acmicpc.net/problem/1019
// 책 페이지
// Written in C++ langs
// 2020. 08. 10.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long CNT[10];
long long N;

void add(long long n, long long digit){
    while(n>0){
        CNT[n%10] += digit;
        n/=10;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    long long A = 1;
    long long B = N;
    long long digit = 1;

    // REF : https://www.slideshare.net/Baekjoon/baekjoon-online-judge-1019
    while(B>=A){
        // A의 끝자리를 0으로 만들어 줌 (더하면서)
        // 가는 동안 포함된 숫자들을 더해줌
        // eg ) 53 -> 60으로 만드는 과정
        while(A%10!=0 && B>=A){
            add(A, digit);
            A++;
        }
        
        if(A>B) break;
        
        // B의 끝자리를 9로 만들어 줌 (빼면서)
        // 가는 동안 포함된 숫자들을 더해줌
        // eg ) 68 -> 59로 만드는 과정
        while(B%10!=9 && B>=A){
            add(B, digit);
            B--;
        }
        
        // 마지막 자리를 제외한 숫자를 빼줌으로써 각 숫자의 개수를 알아냄
        // eg ) A가 10이고 B가 39라면 각 숫자는 끝번호에 3-1+1개(3개)씩을 가지고 있게됨 -> 11, 21, 31
        long long val = B/10 - A/10 + 1;
        
        // 자리수를 계산하여 곱셈하여 더해줌
        // 만약 끝자리가 실질적으로 1의 자리가 아닌 경우 digit 만큼을 곱해주는게 맞음
        for(int i=0; i<10; i++){
            CNT[i] += (val * digit);
        }
        
        // 자릿수를 하나씩 제거해줌
        A/=10;
        B/=10;
        
        digit *= 10;
    }
    
    
    for(int i=0; i<10; i++){
        cout << CNT[i] << " ";
    }
    cout << "\n";
 
    return 0;
    
}

