// https://www.acmicpc.net/problem/1924
// 2007년
// Written in C++ langs
// 2020. 01. 02.
// Wizley

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int total=0;
    int month, day;
    cin >> month >> day;
    
    for(int i=1; i<month; i++){
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
            total += 31;
        }
        else if(i == 2){
            total += 28;
        }
        else{
            total += 30;
        }
    }
    total += day;

    switch(total%7){
        case 1:
            printf("MON\n");
            break;
        case 2:
            printf("TUE\n");
            break;
        case 3:
            printf("WED\n");
            break;
        case 4:
            printf("THU\n");
            break;
        case 5:
            printf("FRI\n");
            break;
        case 6:
            printf("SAT\n");
            break;
        case 0:
            printf("SUN\n");
            break;
    }
}

