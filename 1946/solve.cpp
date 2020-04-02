// https://www.acmicpc.net/problem/1946
// 신입 사원
// Written in C++ langs
// 2020. 04. 01.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int T, N;
int COUNT=0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    int a, b;
    for(int t=0; t<T; t++){
        cin >> N;
        vector<pair<int,int>> grade;
        for(int i=0; i<N; i++){
            cin >> a >> b;
            grade.push_back(make_pair(a,b));
        }
       
        sort(grade.begin(), grade.end());
        COUNT = 1;
        
        int b_grade = grade[0].second;
        
        for(int i=1; i<N; i++){
            if(grade[i].second < b_grade){
                COUNT++;
                b_grade = grade[i].second;
            }
            
        }

        cout << COUNT << "\n";
        COUNT = 0;
    }
    
    return 0;

}


