// https://www.acmicpc.net/problem/12865
// 평범한 배낭
// Written in C++ langs
// 2020. 09. 07.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int,int>> PRODUCT;

//  DP[개수][무게]
int DP[101][100001];
int N, M;
int RESULT = 0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    int w, v;
    for(int i=0; i<N; i++){
        cin >> w >> v;
        PRODUCT.push_back(make_pair(w,v));
    }

    for(int p_cnt=1; p_cnt<=N; p_cnt++){
        
        for(int cur_w=1; cur_w<=M; cur_w++){
            int product_weight = PRODUCT[p_cnt-1].first;
            int product_value = PRODUCT[p_cnt-1].second;
        
            // 해당 품목을 사용하지 못하는 범위일 경우 그 전 결과 값을 가져옴
            if(product_weight > cur_w){
                DP[p_cnt][cur_w] = DP[p_cnt-1][cur_w];
            }
            // 품목을 사용할 수 있는 경우 해당 품목을 사용하지 않는 경우와 사용하는 경우 중에 선택
            else {
                DP[p_cnt][cur_w] = max(DP[p_cnt-1][cur_w], DP[p_cnt-1][cur_w-product_weight]+product_value);
            }
            RESULT = max(RESULT, DP[p_cnt][cur_w]);
        }
        
    }
    
    cout << RESULT << "\n";
    
    return 0;
}

