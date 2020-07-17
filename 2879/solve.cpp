// https://www.acmicpc.net/problem/2879
// 코딩은 예쁘게
// Written in C++ langs
// 2020. 07. 17.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector<int> init;
vector<int> target;
vector<int> diff;

int N;
int COUNT = 0;

void dc(int start, int end){
    if(end - start <= 1){
        if(diff[start] > 0){
            while(diff[start] != 0){
                diff[start]--;
                COUNT++;
            }
        }
        if(diff[start] < 0){
            while(diff[start] != 0){
                diff[start]++;
                COUNT++;
            }
        }
        
        return;
    }
    
    stack<int> st;

    for(int range=start; range<end; range++){
        if(diff[range] > 0){
            if(st.empty())st.push(range);
            else {
                if(diff[st.top()] > 0){
                    st.push(range);
                } else {
                    int r = range;
                    int l = range;
                    int maxv = -9999;
                    while(!st.empty()){
                        l = st.top();
                        maxv = max(maxv, diff[l]);
                        st.pop();
                    }
                    for(int update_range=l; update_range<r; update_range++){
                        diff[update_range] -= maxv;
                    }
                    COUNT += abs(maxv);
                    dc(l, r);
                    st.push(range);
                }
            }
        } else if(diff[range] < 0){
            if(st.empty()) st.push(range);
            else {
                if(diff[st.top()] < 0){
                    st.push(range);
                } else {
                    int r = range;
                    int l = range;
                    int minv = 9999;
                    while(!st.empty()){
                        l = st.top();
                        minv = min(minv, diff[l]);
                        st.pop();
                    }
                    for(int update_range=l; update_range<r; update_range++){
                        diff[update_range] -= minv;
                    }
                    COUNT += abs(minv);
                    dc(l, r);
                    st.push(range);
                }
            }
        } else {
            if(st.empty()) continue;
            else {
                int r = range;
                int l = st.top();
                
                if(diff[st.top()] > 0){
                    int minv = 9999;
                    while(!st.empty()){
                        l = st.top();
                        minv = min(minv, diff[l]);
                        st.pop();
                    }
                    for(int update_range=l; update_range<r; update_range++){
                        diff[update_range] -= minv;
                    }
                    COUNT += abs(minv);
                } else {
                    int maxv = -9999;
                    while(!st.empty()){
                        l = st.top();
                        maxv = max(maxv, diff[l]);
                        st.pop();
                    }
                    for(int update_range=l; update_range<r; update_range++){
                        diff[update_range] -= maxv;
                    }
                    COUNT += abs(maxv);
                }
                dc(l, r);
            }
        }
    }

    if(!st.empty()){
        int r = st.top()+1;
        int l = st.top();
        
        if(diff[st.top()] > 0){
            int minv = 9999;
            while(!st.empty()){
                l = st.top();
                minv = min(minv, diff[l]);
                st.pop();
            }
            for(int update_range=l; update_range<r; update_range++){
                diff[update_range] -= minv;
            }
            COUNT += abs(minv);
        } else {
            int maxv = -9999;
            while(!st.empty()){
                l = st.top();
                maxv = max(maxv, diff[l]);
                st.pop();
            }
            for(int update_range=l; update_range<r; update_range++){
                diff[update_range] -= maxv;
            }
            COUNT += abs(maxv);
        }
        dc(l, r);
    }
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    int input;
    for(int n=0; n<N; n++){
        cin >> input;
        init.push_back(input);
    }
    
    for(int n=0; n<N; n++){
        cin >> input;
        target.push_back(input);
        
        diff.push_back(target[n] - init[n]);
    }
    
    dc(0, N);
    
    cout << COUNT << "\n";
    
    return 0;
    
}

