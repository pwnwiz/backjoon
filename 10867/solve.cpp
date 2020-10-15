// https://www.acmicpc.net/problem/10867
// 중복 빼고 정렬하기
// Written in C++ langs
// 2020. 10. 15.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N;

int partition(vector<int> &v, int left, int right){
    int mid = (left+right)/2;
    swap(v[left], v[mid]);
    int pivot = v[left];
    
    int l = left;
    int r = right;
    
    while(l<r){
        
        while(pivot < v[r]){
            r--;
        }
        
        while(l<r && pivot >= v[l]){
            l++;
        }
        
        swap(v[l], v[r]);
    }
    
    v[left] = v[l];
    v[l] = pivot;
    
    return l;
}

void quickSort(vector<int> &v, int l, int r){
    if(l>=r) return;
    
    int pi = partition(v, l, r);
    quickSort(v, l, pi-1);
    quickSort(v, pi+1, r);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    cin >> N;
    
    set<int> s;
    
    int input;
    for(int i=0; i<N; i++){
        cin >> input;
        s.insert(input);
    }
    
    vector<int> v;
    
    for(auto ss : s){
        v.push_back(ss);
    }

    for(auto vv : v){
        cout << vv << " ";
    }
    cout << "\n";
}

