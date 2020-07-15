// https://www.acmicpc.net/problem/1725
// 히스토그램
// Written in C++ langs
// 2020. 07. 15.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N;
long RESULT = 0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> histogram;
    
    cin >> N;
    
    histogram.push_back(0);
    int input;
    for(int h=0; h<N; h++){
        cin >> input;
        histogram.push_back(input);
    }
    histogram.push_back(0);
    
    stack<int> st;
    
    for(int r=0; r<histogram.size(); r++){

        while(!st.empty()){
            int l = st.top();

            if(histogram[l] > histogram[r]){
                st.pop();

                long w = r - (st.top() + 1);
                long h = histogram[l];

                RESULT = max(RESULT, w*h);

            } else {
                break;
            }
        }
        st.push(r);
    }
    
    
    cout << RESULT << "\n";
    
    return 0;
    
}

