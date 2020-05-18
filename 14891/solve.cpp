// https://www.acmicpc.net/problem/14891
// 톱니바퀴
// Written in C++ langs
// 2020. 05. 18.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int N;
vector<pair<int,int>> COMMAND;
deque<char> A, B, C, D;

void simulation(){
    for(int i=0; i<COMMAND.size(); i++){
        // 1,2,3,4
        int idx = COMMAND[i].first;
        
        // -1 반시계
        // +1 시계
        int direct = COMMAND[i].second;
        
        // idx 톱니를 기준으로 2번째와 6번째가 상극인지 확인
        bool AB, BC, CD;
        (A[2] != B[6]) ? AB = true : AB = false;
        (B[2] != C[6]) ? BC = true : BC = false;
        (C[2] != D[6]) ? CD = true : CD = false;
        
        // N => 0, S => 1
        switch(idx){
            case 1:
                if(direct == 1){
                    int tmp = A.back();
                    A.pop_back();
                    A.push_front(tmp);
                } else {
                    int tmp = A.front();
                    A.pop_front();
                    A.push_back(tmp);
                }
                
                if(AB){
                    int cur_direct = direct * -1;
                    if(cur_direct == 1){
                        int tmp = B.back();
                        B.pop_back();
                        B.push_front(tmp);
                    } else {
                        int tmp = B.front();
                        B.pop_front();
                        B.push_back(tmp);
                    }
                    
                    if(BC){
                        int cur_direct2 = cur_direct * -1;
                        if(cur_direct2 == 1){
                            int tmp = C.back();
                            C.pop_back();
                            C.push_front(tmp);
                        } else {
                            int tmp = C.front();
                            C.pop_front();
                            C.push_back(tmp);
                        }
                        
                        if(CD){
                            int cur_direct3 = cur_direct2 * -1;
                            if(cur_direct3 == 1){
                                int tmp = D.back();
                                D.pop_back();
                                D.push_front(tmp);
                            } else {
                                int tmp = D.front();
                                D.pop_front();
                                D.push_back(tmp);
                            }
                            
                        }
                    }
                }
                break;
            case 2:
                if(direct == 1){
                    int tmp = B.back();
                    B.pop_back();
                    B.push_front(tmp);
                } else {
                    int tmp = B.front();
                    B.pop_front();
                    B.push_back(tmp);
                }
                
                if(AB){
                    int cur_direct = direct * -1;
                    if(cur_direct == 1){
                        int tmp = A.back();
                        A.pop_back();
                        A.push_front(tmp);
                    } else {
                        int tmp = A.front();
                        A.pop_front();
                        A.push_back(tmp);
                    }
                }
                
                if(BC){
                    int cur_direct = direct * -1;
                    if(cur_direct == 1){
                        int tmp = C.back();
                        C.pop_back();
                        C.push_front(tmp);
                    } else {
                        int tmp = C.front();
                        C.pop_front();
                        C.push_back(tmp);
                    }
                    
                    if(CD){
                        int cur_direct2 = cur_direct * -1;
                        if(cur_direct2 == 1){
                            int tmp = D.back();
                            D.pop_back();
                            D.push_front(tmp);
                        } else {
                            int tmp = D.front();
                            D.pop_front();
                            D.push_back(tmp);
                        }
                    }
                }
                break;
            case 3:
                if(direct == 1){
                    int tmp = C.back();
                    C.pop_back();
                    C.push_front(tmp);
                } else {
                    int tmp = C.front();
                    C.pop_front();
                    C.push_back(tmp);
                }
                
                if(CD){
                    int cur_direct = direct * -1;
                    if(cur_direct == 1){
                        int tmp = D.back();
                        D.pop_back();
                        D.push_front(tmp);
                    } else {
                        int tmp = D.front();
                        D.pop_front();
                        D.push_back(tmp);
                    }
                }
                
                if(BC){
                    int cur_direct = direct * -1;
                    if(cur_direct == 1){
                        int tmp = B.back();
                        B.pop_back();
                        B.push_front(tmp);
                    } else {
                        int tmp = B.front();
                        B.pop_front();
                        B.push_back(tmp);
                    }
                    
                    if(AB){
                        int cur_direct2 = cur_direct * -1;
                        if(cur_direct2 == 1){
                            int tmp = A.back();
                            A.pop_back();
                            A.push_front(tmp);
                        } else {
                            int tmp = A.front();
                            A.pop_front();
                            A.push_back(tmp);
                        }
                    }
                }
                break;
            case 4:
                if(direct == 1){
                    int tmp = D.back();
                    D.pop_back();
                    D.push_front(tmp);
                } else {
                    int tmp = D.front();
                    D.pop_front();
                    D.push_back(tmp);
                }
                
                if(CD){
                    int cur_direct = direct * -1;
                    if(cur_direct == 1){
                        int tmp = C.back();
                        C.pop_back();
                        C.push_front(tmp);
                    } else {
                        int tmp = C.front();
                        C.pop_front();
                        C.push_back(tmp);
                    }
                    
                    if(BC){
                        int cur_direct2 = cur_direct * -1;
                        if(cur_direct2 == 1){
                            int tmp = B.back();
                            B.pop_back();
                            B.push_front(tmp);
                        } else {
                            int tmp = B.front();
                            B.pop_front();
                            B.push_back(tmp);
                        }
                        
                        if(AB){
                            int cur_direct3 = cur_direct2 * -1;
                            if(cur_direct3 == 1){
                                int tmp = A.back();
                                A.pop_back();
                                A.push_front(tmp);
                            } else {
                                int tmp = A.front();
                                A.pop_front();
                                A.push_back(tmp);
                            }
                            
                        }
                    }
                }
                break;
        }
    }
    int score = 0;
    if(A[0] == '1') score += 1;
    if(B[0] == '1') score += 2;
    if(C[0] == '1') score += 4;
    if(D[0] == '1') score += 8;
    
    cout << score << "\n";
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    char in;
    for(int j=0; j<8; j++){
        cin >> in;
        A.push_back(in);
    }

    for(int j=0; j<8; j++){
        cin >> in;
        B.push_back(in);
    }
    
    for(int j=0; j<8; j++){
        cin >> in;
        C.push_back(in);
    }
    
    for(int j=0; j<8; j++){
        cin >> in;
        D.push_back(in);
    }
    
    cin >> N;
    int t1, t2;
    for(int i=0; i<N; i++){
        cin >> t1 >> t2;
        COMMAND.push_back(make_pair(t1,t2));
    }
    
    simulation();
   
    return 0;
    
}

