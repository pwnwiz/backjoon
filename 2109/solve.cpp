// https://www.acmicpc.net/problem/2109
// 순회 강연
// Written in C++ langs
// 2020. 04. 01.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct LECTURE{
    int pay;
    int due_date;
}LECTURE;

vector<LECTURE> LECTURES;
int NO;
int DAY=0;
int PAYMENT=0;

bool compare(const LECTURE &A, const LECTURE &B){
    if(A.due_date > B.due_date) return true;
    return false;
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> NO;
    int pay, day;
    for(int i=0; i<NO; i++){
        cin >> pay >> day;
        LECTURES.push_back({pay, day});
    }
    
    if(NO==0){
        cout << "0\n";
        exit(0);
    }
    
    sort(LECTURES.begin(), LECTURES.end(), compare);
    DAY = LECTURES[0].due_date;
  
    while(LECTURES.size()>0 && DAY>0){
        int max_val = -1;
        int idx = -1;
        for(int i=0; i<LECTURES.size(); i++){
            if(LECTURES[i].due_date >=DAY){
                if(LECTURES[i].pay > max_val){
                    max_val = LECTURES[i].pay;
                    idx = i;
                }
            }
            
            else{
                break;
            }
        }
        
        if(max_val > 0 && idx >= 0){
            PAYMENT += max_val;
            LECTURES.erase(LECTURES.begin()+idx);
        }
        
        DAY--;
        
    }

    cout << PAYMENT << "\n";
    
    return 0;
    
}

