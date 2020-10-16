// https://www.acmicpc.net/problem/11931
// 수 정렬하기 4
// Written in C++ langs
// 2020. 10. 16.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

void merge(vector<int> &v, int left, int right){
    int mid = (left+right)/2;
    
    int l = left;
    int r = mid+1;
    
    auto v2 = v;
    int idx = left;
    
    while(l<=mid && r<=right){
        
        if(v[l] > v[r]){
            v2[idx++] = v[l++];
        }
        
        else {
            v2[idx++] = v[r++];
        }
    }
    
    while(l<=mid){
        v2[idx++] = v[l++];
    }
    
    while(r<=right){
        v2[idx++] = v[r++];
    }
    
    v = v2;
    
}

void mergeSort(vector<int> &v, int left, int right){
    if(left>=right) return;
    
    int mid = (left+right)/2;
    mergeSort(v, left, mid);
    mergeSort(v, mid+1, right);
    merge(v, left, right);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    vector<int> v(N);
    
    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<>());
    
    for(auto vv : v){
        cout << vv << "\n";
    }
    
    return 0;
}

