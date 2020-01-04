// https://www.acmicpc.net/problem/15353
// 큰수 A+B (2)
// Written in C++ langs
// 2020. 01. 05.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string A;
string B;
string RES="";

int main(){
    cin >> A >> B;
    int carry = 0;
    
    if(A.length() < B.length()) A.swap(B);
    
    for(int i=B.length(); i>0; i--){
        int b = B.back() - '0';
        B.pop_back();
        
        int a = A.back() - '0';
        A.pop_back();
        
        if(a+b+carry>=10){
            RES.append(1, (a+b+carry)%10+'0');
            carry = 1;
        }
        
        else{
            RES.append(1, (a+b+carry)%10+'0');
            carry = 0;
        }
    }
    
    for(int i=A.length() - B.length(); i>0; i--){
        int c = A.back() - '0';
        A.pop_back();
        RES.append(1, (c+carry)%10+'0');
        c+carry>=10 ? carry=1 : carry=0;
    
    }
    if(carry) RES.append(1, '1');

    reverse(RES.begin(), RES.end());
    cout << RES << endl;
    
    return 0;
}

