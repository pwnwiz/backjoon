// https://www.acmicpc.net/problem/3015
// 오아시스 재결합
// Written in C++ langs
// 2020. 07. 16.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N;
long long COUNT = 0;

int main(){
    ios_base :: sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    // 스택은 비교되는 대상이 볼 가능성이 있는 값들이 저장됨
    // first -> 키
    // second -> 동일한 값 카운트
    stack<pair<long long,long long>> st;

    long long input;
    for(int i=0; i<N; i++){
        cin >> input;
        // 동일한 키 카운트
        long long same = 1;
        
        // 현재 사람의 키가 top보다 크면 현재 사람 전의 stack의 값들을 더 이상 보지 못함
        while(!st.empty() && st.top().first <= input){

            // 키가 동일한 경우 second의 값을 증가시켜줌
            if(st.top().first == input){
                COUNT += st.top().second;
                same = st.top().second + 1;
                st.pop();
            }
            
            // 키가 큰 경우에는 다음 사람이 절대 보지 못하는 사람의 정보를 stack에서 pop
            else {
                COUNT += st.top().second;
                st.pop();
                same = 1;
            }
        }
        
        // 현재 사람이 top을 볼 수 있는 경우
        if(!st.empty()) COUNT++;

        st.push(make_pair(input, same));
        
    }
    
    cout << COUNT << "\n";
 
    return 0;
}

