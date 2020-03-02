// https://www.acmicpc.net/problem/1517
// 버블 소트
// Written in C++ langs
// 2020. 03. 02.
// Wizley

#include <algorithm>
#include <iostream>

using namespace std;
int N;

int ARR[500001]={0,};
int TMP[500001]={0,};
long long COUNT=0;

void merge(int l, int r, int mid){
    int a = l;
    int b = mid+1;
    int idx = l;

    while(a<=mid && b<=r){
        if(ARR[a]>ARR[b]){
            TMP[idx++] = ARR[b++];
            COUNT += mid - a + 1;
        }
        else{
            TMP[idx++] = ARR[a++];
        }
    }
    
    while(a<=mid){
        TMP[idx++] = ARR[a++];
    }
    
    while(b<=r){
        TMP[idx++] = ARR[b++];
    }
    
    for(int i=l; i<=r; i++){
        ARR[i] = TMP[i];
    }
}

void mergeSort(int l, int r){
    int mid = (l+r)/2;
    
    if(l < r){
        mergeSort(l, mid);
        mergeSort(mid+1, r);
        merge(l, r, mid);
    }
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    for(int i=1; i<=N; i++){
        cin >> ARR[i];
    }
    
    mergeSort(1, N);
    cout << COUNT << "\n";
    
    return 0;
    
}

