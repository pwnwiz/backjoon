// https://www.acmicpc.net/problem/1406
// 에디터
// Written in C++ langs
// 2020. 01. 30.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

list<char> LIST;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string word;
    int count;
    
    cin >> word >> count;
    
    for(int i=0; i<word.length(); i++)
        LIST.push_back(word[i]);

    list<char>::iterator cursor = LIST.end();
    
    for(int i=0; i<count; i++){
        char command;
        char p_word;
    
        cin >> command;
        switch(command){
            case 'L':
                if(cursor != LIST.begin()) cursor--;
                break;
            case 'D':
                if(cursor != LIST.end()) cursor++;
                break;
            case 'B':
                if(cursor != LIST.begin()){
                    cursor--;
                    cursor = LIST.erase(cursor);
                }
                break;
            case 'P':
                cin >> p_word;
                LIST.insert(cursor, p_word);
                break;
        }
    }
    
    for(auto &chr : LIST)
        cout << chr;
    
    cout << "\n";
    
    return 0;
}



