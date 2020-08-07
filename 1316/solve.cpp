// https://www.acmicpc.net/problem/1316
// 그룹 단어 체커
// Written in C++ langs
// 2020. 08. 07.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    int total = 0;
    
    string input;
    for(int i=0; i<N; i++){
        cin >> input;
        
        bool used[26] = {0,};
        
        char prev = input[0];
        used[input[0]-'a'] = true;
        
        if(input.size() == 1){
            total++;
        }
        else {
            for(int j=1; j<input.size(); j++){
                if(!used[input[j]-'a']){
                    used[input[j]-'a'] = true;
                }
                
                else{
                    if(prev != input[j]){
                        break;
                    }
                }
                
                if(j == input.size() -1){
                    total ++;
                }
                
                prev = input[j];
            }
        }
    }
    
    cout << total << "\n";
    

    return 0;
    
}

