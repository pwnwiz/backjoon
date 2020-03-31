// https://www.acmicpc.net/problem/2104
// 부분배열 고르기
// Written in C++ langs
// 2020. 03. 31.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int ARR[1000000]={0,};

long long mergeSort(int left, int right){
    
    if(left+1 == right){
        return (long long)ARR[left] * ARR[left];
    }
    
    int mid = (left + right) / 2;
    long long l = mergeSort(left, mid);
    long long r = mergeSort(mid, right);
    long long max_lr = max(l, r);

    int m_left = mid-1;
    int m_right = mid;
    long long m = ARR[m_left]+ARR[m_right];
    long long min_m = min(ARR[m_left],ARR[m_right]);
    long long max_m = max(max_lr, m*min_m);

    while(m_left >= left+1 && m_right < right-1){
        if(ARR[m_left-1] <= ARR[m_right+1]){
            m_right++;
            m += ARR[m_right];
            min_m = min(min_m, (long long)ARR[m_right]);
        }
        
        else{
            m_left--;
            m += ARR[m_left];
            min_m = min(min_m, (long long)ARR[m_left]);
        }
        max_m = max(max_m, m*min_m);
    }
    
    while(m_left >= left+1){
        m_left--;
        m += ARR[m_left];
        min_m = min(min_m, (long long)ARR[m_left]);
        max_m = max(max_m, m*min_m);
    }
    
    while(m_right < right-1){
        m_right++;
        m += ARR[m_right];
        min_m = min(min_m, (long long)ARR[m_right]);
        max_m = max(max_m, m*min_m);
    }

    return max_m;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> ARR[i];
    }
    
    cout << mergeSort(0, N) << "\n";

    return 0;
    
}

