// https://www.acmicpc.net/problem/2258
// 정육점
// Written in C++ langs
// 2020. 04. 01.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct MEAT{
    int weight;
    int price;
}MEAT;

vector<MEAT> MEATS;
int N, M;
long long TOTAL=99999999999;

bool compare(const MEAT &A, const MEAT &B){
    if(A.price < B.price) return true;
    if(A.price == B.price && A.weight > B.weight) return true;
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int weight;
    int price;
    for(int i=0; i<N; i++){
        cin >> weight >> price;
        MEATS.push_back({weight, price});
    }

    sort(MEATS.begin(), MEATS.end(), compare);

    int t_weight = 0;
    int same_price = 0;
    for(int i=0; i<N; i++){
        t_weight += MEATS[i].weight;

        if(i!=0 && MEATS[i].price == MEATS[i-1].price){
            same_price += MEATS[i-1].price;
        }

        else{
            same_price = 0;
        }

        if(t_weight >= M){
            TOTAL = min(TOTAL, (long long)MEATS[i].price + same_price);
        }
    }

    (TOTAL == 99999999999) ? cout << "-1\n" : cout << TOTAL << "\n";

    return 0;

}


