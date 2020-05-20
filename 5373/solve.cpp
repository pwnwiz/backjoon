// https://www.acmicpc.net/problem/5373
// 큐빙
// Written in C++ langs
// 2020. 05. 20.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<string> COMMAND;

int T;
int N;

// [0] U
// [1] D
// [2] F
// [3] B
// [4] L
// [5] R
char CUBE[6][3][3] = {
    {
        {'w','w','w'},
        {'w','w','w'},
        {'w','w','w'}
    },
    {
        {'y','y','y'},
        {'y','y','y'},
        {'y','y','y'}
    },
    {
        {'r','r','r'},
        {'r','r','r'},
        {'r','r','r'}
    },
    {
        {'o','o','o'},
        {'o','o','o'},
        {'o','o','o'}
    },
    {
        {'g','g','g'},
        {'g','g','g'},
        {'g','g','g'}
    },
    {
        {'b','b','b'},
        {'b','b','b'},
        {'b','b','b'}
    }
};

char COPY_CUBE[6][3][3];

void print(){
    for(int i=0; i<6; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                cout << COPY_CUBE[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

void init_cube(){
    for(int i=0; i<6; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                COPY_CUBE[i][j][k] = CUBE[i][j][k];
            }
        }
    }
}

void simulation(){
    for(int i=0; i<COMMAND.size(); i++){
        char loc = COMMAND[i][0];
        char dir = COMMAND[i][1];

        int cur = -1;
        char A[3], B[3], C[3], D[3];
        switch(loc){
            case 'U':
                cur = 0;
                for(int i=0; i<3; i++){
                    A[i] = COPY_CUBE[3][0][i];
                    B[i] = COPY_CUBE[4][0][i];
                    C[i] = COPY_CUBE[2][0][i];
                    D[i] = COPY_CUBE[5][0][i];
                }
                
                if(dir == '+'){
                    for(int i=0; i<3; i++){
                        COPY_CUBE[5][0][i] = A[i];
                        COPY_CUBE[2][0][i] = D[i];
                        COPY_CUBE[4][0][i] = C[i];
                        COPY_CUBE[3][0][i] = B[i];
                    }
                } else {
                    for(int i=0; i<3; i++){
                        COPY_CUBE[4][0][i] = A[i];
                        COPY_CUBE[2][0][i] = B[i];
                        COPY_CUBE[5][0][i] = C[i];
                        COPY_CUBE[3][0][i] = D[i];
                    }
                }
                break;
            case 'D':
                cur = 1;
                for(int i=0; i<3; i++){
                    A[i] = COPY_CUBE[2][2][i];
                    B[i] = COPY_CUBE[4][2][i];
                    C[i] = COPY_CUBE[3][2][i];
                    D[i] = COPY_CUBE[5][2][i];
                }
                if(dir == '+'){
                    for(int i=0; i<3; i++){
                        COPY_CUBE[5][2][i] = A[i];
                        COPY_CUBE[2][2][i] = B[i];
                        COPY_CUBE[4][2][i] = C[i];
                        COPY_CUBE[3][2][i] = D[i];
                    }
                } else {
                    for(int i=0; i<3; i++){
                        COPY_CUBE[4][2][i] = A[i];
                        COPY_CUBE[3][2][i] = B[i];
                        COPY_CUBE[5][2][i] = C[i];
                        COPY_CUBE[2][2][i] = D[i];
                    }
                }
                break;
            case 'F':
                cur = 2;
                if(dir == '+'){
                    for(int i=0; i<3; i++){
                        A[i] = COPY_CUBE[0][2][i];
                        B[i] = COPY_CUBE[4][2-i][2];
                        C[i] = COPY_CUBE[1][0][i];
                        D[i] = COPY_CUBE[5][2-i][0];
                    }
                    
                    for(int i=0; i<3; i++){
                        COPY_CUBE[5][i][0] = A[i];
                        COPY_CUBE[0][2][i] = B[i];
                        COPY_CUBE[4][i][2] = C[i];
                        COPY_CUBE[1][0][i] = D[i];
                    }
                } else {
                    for(int i=0; i<3; i++){
                        A[i] = COPY_CUBE[0][2][2-i];
                        B[i] = COPY_CUBE[4][i][2];
                        C[i] = COPY_CUBE[1][0][2-i];
                        D[i] = COPY_CUBE[5][i][0];
                    }
                    for(int i=0; i<3; i++){
                        COPY_CUBE[4][i][2] = A[i];
                        COPY_CUBE[1][0][i] = B[i];
                        COPY_CUBE[5][i][0] = C[i];
                        COPY_CUBE[0][2][i] = D[i];
                    }
                }

                break;
            case 'B':
                cur = 3;
                if(dir == '+'){
                    for(int i=0; i<3; i++){
                        A[i] = COPY_CUBE[0][0][2-i];
                        B[i] = COPY_CUBE[5][2-i][2];
                        C[i] = COPY_CUBE[1][2][2-i];
                        D[i] = COPY_CUBE[4][i][0];
                    }
                    for(int i=0; i<3; i++){
                        COPY_CUBE[4][i][0] = A[i];
                        COPY_CUBE[0][0][2-i] = B[i];
                        COPY_CUBE[5][i][2] = C[i];
                        COPY_CUBE[1][2][i] = D[i];
                    }
                } else {
                    for(int i=0; i<3; i++){
                        A[i] = COPY_CUBE[0][0][i];
                        B[i] = COPY_CUBE[5][i][2];
                        C[i] = COPY_CUBE[1][2][i];
                        D[i] = COPY_CUBE[4][i][0];
                    }
                    for(int i=0; i<3; i++){
                        COPY_CUBE[5][i][2] = A[i];
                        COPY_CUBE[1][2][2-i] = B[i];
                        COPY_CUBE[4][i][0] = C[i];
                        COPY_CUBE[0][0][2-i] = D[i];
                    }
                }
                break;
            case 'L':
                cur = 4;
                if(dir == '+'){
                    for(int i=0; i<3; i++){
                        A[i] = COPY_CUBE[0][i][0];
                        B[i] = COPY_CUBE[3][2-i][2];
                        C[i] = COPY_CUBE[1][2-i][0];
                        D[i] = COPY_CUBE[2][2-i][0];
                    }
                    for(int i=0; i<3; i++){
                        COPY_CUBE[2][i][0] = A[i];
                        COPY_CUBE[0][i][0] = B[i];
                        COPY_CUBE[3][i][2] = C[i];
                        COPY_CUBE[1][2-i][0] = D[i];
                    }
                } else {
                    for(int i=0; i<3; i++){
                        A[i] = COPY_CUBE[0][2-i][0];
                        B[i] = COPY_CUBE[3][i][2];
                        C[i] = COPY_CUBE[1][i][0];
                        D[i] = COPY_CUBE[2][i][0];
                    }
                    for(int i=0; i<3; i++){
                        COPY_CUBE[3][i][2] = A[i];
                        COPY_CUBE[1][2-i][0] = B[i];
                        COPY_CUBE[2][i][0] = C[i];
                        COPY_CUBE[0][i][0] = D[i];
                    }
                }
                break;
            case 'R':
                cur = 5;
                if(dir == '+'){
                    for(int i=0; i<3; i++){
                        A[i] = COPY_CUBE[0][2-i][2];
                        B[i] = COPY_CUBE[2][2-i][2];
                        C[i] = COPY_CUBE[1][i][2];
                        D[i] = COPY_CUBE[3][2-i][0];
                    }
                    for(int i=0; i<3; i++){
                        COPY_CUBE[3][i][0] = A[i];
                        COPY_CUBE[0][2-i][2] = B[i];
                        COPY_CUBE[2][i][2] = C[i];
                        COPY_CUBE[1][i][2] = D[i];
                    }
                } else {
                    for(int i=0; i<3; i++){
                        A[i] = COPY_CUBE[0][i][2];
                        B[i] = COPY_CUBE[2][i][2];
                        C[i] = COPY_CUBE[1][2-i][2];
                        D[i] = COPY_CUBE[3][i][0];
                    }
                    for(int i=0; i<3; i++){
                        COPY_CUBE[2][i][2] = A[i];
                        COPY_CUBE[1][i][2] = B[i];
                        COPY_CUBE[3][i][0] = C[i];
                        COPY_CUBE[0][2-i][2] = D[i];
                    }
                }
                break;
        }
        
        char cur_side[3][3];
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cur_side[i][j] = COPY_CUBE[cur][i][j];
            }
        }
        
        if(dir == '+'){
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    COPY_CUBE[cur][i][j] = cur_side[2-j][i];
                }
            }
        } else {
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    COPY_CUBE[cur][i][j] = cur_side[j][2-i];
                }
            }
        }
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << COPY_CUBE[0][i][j];
        }
        cout << "\n";
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N;
        
        init_cube();
        
        string input;
        for(int j=0; j<N; j++){
            cin >> input;
            COMMAND.push_back(input);
        }
        
        simulation();
        
        COMMAND.clear();
    }
    
    return 0;
    
}

