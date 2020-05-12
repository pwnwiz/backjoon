// https://www.acmicpc.net/problem/16506
// CPU
// Written in C++ langs
// 2020. 05. 12.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

int N;

void parser(string opcode, int rD, int rA, int rB){
    string machine;
    
    if(opcode == "ADD"){
        machine += "00000";
    } else if (opcode == "ADDC"){
        machine += "00001";
    } else if (opcode == "SUB"){
        machine += "00010";
    } else if (opcode == "SUBC"){
        machine += "00011";
    } else if (opcode == "MOV"){
        machine += "00100";
    } else if (opcode == "MOVC"){
        machine += "00101";
    } else if (opcode == "AND"){
        machine += "00110";
    } else if (opcode == "ANDC"){
        machine += "00111";
    } else if (opcode == "OR"){
        machine += "01000";
    } else if (opcode == "ORC"){
        machine += "01001";
    } else if (opcode == "NOT"){
        machine += "01010";
    } else if (opcode == "MULT"){
        machine += "01100";
    } else if (opcode == "MULTC"){
        machine += "01101";
    } else if (opcode == "LSFTL"){
        machine += "01110";
    } else if (opcode == "LSFTLC"){
        machine += "01111";
    } else if (opcode == "LSFTR"){
        machine += "10000";
    } else if (opcode == "LSFTRC"){
        machine += "10001";
    } else if (opcode == "ASFTR"){
        machine += "10010";
    } else if (opcode == "ASFTRC"){
        machine += "10011";
    } else if (opcode == "RL"){
        machine += "10100";
    } else if (opcode == "RLC"){
        machine += "10101";
    } else if (opcode == "RR"){
        machine += "10110";
    } else if (opcode == "RRC"){
        machine += "10111";
    }
    
    machine += "0";
    machine += (bitset<3>(rD)).to_string();
    machine += (bitset<3>(rA)).to_string();
    
    if(opcode[opcode.size()-1] == 'C'){
        machine += (bitset<4>(rB)).to_string();
    } else {
        machine += (bitset<3>(rB)).to_string();
        machine += "0";
    }
    
    cout << machine << "\n";
    
    
}

void lexer(){
    string opcode;
    int rD;
    int rA;
    int rB;
    
    cin >> opcode >> rD >> rA >> rB;

    parser(opcode, rD, rA, rB);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; i++){
        lexer();
    }
    
    return 0;
    
}

