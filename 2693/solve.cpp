// https://www.acmicpc.net/problem/2693
// N번째 큰 수
// Written in C++ langs
// 2020. 10. 16.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T;
int POSITION = 3;

int partition(vector<int> &v, int left, int right){
    int mid = (left+right)/2;
    swap(v[left], v[mid]);
    int pivot = v[left];
    
    int l = left;
    int r = right;
    
    while(l<r){
        
        while(pivot > v[r]){
            r--;
        }
        
        while(l<r && pivot <= v[l]){
            l++;
        }
        
        swap(v[l], v[r]);
    }
    
    v[left] = v[l];
    v[l] = pivot;
    return l;
}

void quickSort(vector<int> &v, int left, int right){
    if(left>=right) return;
    
    int pi = partition(v, left, right);
    if(left<=POSITION)quickSort(v, left, pi-1);
    if(pi+1<=POSITION)quickSort(v, pi+1, right);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    for(int t=0; t<T; t++){
        vector<int> v(10);
        for(int j=0; j<10; j++){
            cin >> v[j];
        }
        
        quickSort(v, 0, v.size()-1);
        cout << v[2] << "\n";
    }
    
}

