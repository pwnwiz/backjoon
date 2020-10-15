// https://www.acmicpc.net/problem/2822
// 점수 계산
// Written in C++ langs
// 2020. 10. 15.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int partition(vector<pair<int,int>> &v, int left, int right){
    int mid = (left + right)/2;
    swap(v[left], v[mid]);
    
    int l = left;
    int r = right;
    int pivot = v[left].first;
    int pivot_idx = v[left].second;
    
    while(l<r){
        while(pivot > v[r].first){
            r--;
        }
        
        while(l<r && pivot <= v[l].first){
            l++;
        }
        swap(v[l], v[r]);
    }
    
    v[left] = v[l];
    v[l]= {pivot,pivot_idx};
    
    return l;
}

void quickSort(vector<pair<int,int>> &v, int left, int right){
    if(left >= right) return;
    
    int pivot = partition(v, left, right);
    quickSort(v, left, pivot-1);
    quickSort(v, pivot+1, right);
}

void merge(vector<int> &v, int left, int right){
    if(left >= right) return;
    
    int mid = (left+right)/2;
    
    int l = left;
    int r = mid+1;
    
    vector<int> v2 = v;
    int idx = left;
    
    while(l<=mid && r<=right){
        if(v[l] < v[r]){
            v2[idx++]=v[l++];
        } else {
            v2[idx++]=v[r++];
        }
    }
    
    while(l<=mid){
        v2[idx++]=v[l++];
    }
    
    while(r<=right){
        v2[idx++]=v[r++];
    }
    
    v = v2;
}

void mergeSort(vector<int> &v, int left, int right){
    
    if(left >= right) return;
    
    int mid = (left+right)/2;
    mergeSort(v, left, mid);
    mergeSort(v, mid+1, right);
    merge(v, left, right);
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<pair<int,int>> v(8);
    
    for(int i=0; i<8; i++){
        cin >> v[i].first;
        v[i].second = i+1;
    }
    
    quickSort(v, 0, v.size()-1);
    
    vector<int> v2;

    int sum = 0;
    for(int i=0; i<5; i++){
        sum += v[i].first;
        v2.push_back(v[i].second);
    }
    
    mergeSort(v2, 0, v2.size()-1);
    
    cout << sum << "\n";
    for(auto vv : v2){
        cout << vv << " ";
    }
    
    return 0;
}

