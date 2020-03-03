// https://www.acmicpc.net/problem/2261
// 가장 가까운 두 점
// Written in C++ langs
// 2020. 03. 03.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>

using namespace std;

typedef struct POINT{
    int x;
    int y;
    POINT(){}
    POINT(int x, int y) : x(x), y(y){}
    bool operator < (const POINT &v) const {
        if(y == v.y){
            return x < v.x;
        } else {
            return y < v.y;
        }
    }
}POINT;

int N;
long long dest;

bool xCompare(const POINT &A, const POINT &B){
    return A.x < B.x;
}

bool yCompare(const POINT &A, const POINT &B){
    return A.y < B.y;
}

int getDistance(POINT A, POINT B){
    return (B.x-A.x)*(B.x-A.x) + (B.y-A.y)*(B.y-A.y);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<POINT> coordinates(N);

    for(int i=0; i<N; i++){
        cin >> coordinates[i].x >> coordinates[i].y;
    }
    
    sort(coordinates.begin(), coordinates.end(), xCompare);
    
    // STL :: set
    // 원하는 key를 신속히 찾고 key가 정렬되길 원할때 사용
    // 중위선회의 방식으로 구현됨
    // 아래의 조건일 때 사용됨
    // 1) 정렬해야 됨
    // 2) key가 있는지 없는지 알아야 할 경우
    // 3) 많은 자료를 저장하고, 검색 속도가 빨라야 할 때
    set<POINT> candidate = {coordinates[0], coordinates[1]};
    int dist = getDistance(coordinates[0], coordinates[1]);

    // line sweep
    // 1번부터 M-1번 까지의 점이 있을 경우 가장 가까운 점의 거리가 d
    // M 번째 점에 대하여 가장 가까운 두 점의 거리를 구해야 됨
    // 가장 가까운 점이 d이기 때문에 M번 점의 x좌표와 차이가 d이하인 점이 후보가 됨
    // candidate는 d만큼의 거리안에 존재하는 점의 목록
    // candidate 블록을 기준으로 d가 y점에 대해서도 d이하여야 최소 거리가 됨
    int s = 0;
    for(int i=2; i<N; i++){
        POINT cur = coordinates[i];
        
        // STAGE 1
        // coordinates를 순회하면서 미리 정렬된 x의 값을 토대로 d 내의 값을 candidate에 추가
        while(s < i){
            auto can = coordinates[s];
            int x_diff = cur.x - can.x;
            if(x_diff * x_diff > dist){
                candidate.erase(can);
                s++;
            }
            else{
                break;
            }
        }
        
        // STAGE 2
        // y에 대해서 d 내의 범위를 구한 뒤 최소 거리인지 확인하는 루틴
        // 이분탐색을 사용하여 y축에 대한 범위를 lower / upper로 구해와 해당 부분만 순회
        int d = (int)sqrt((double)dist)+1;
        
        auto low_p = POINT(-100000, cur.y-d);
        auto high_p = POINT(100000, cur.y+d);
        
        auto lower = candidate.lower_bound(low_p);
        auto upper = candidate.upper_bound(high_p);

        for(auto can = lower; can != upper; can++){
            int tmp_dist = getDistance(cur, *can);
            if(tmp_dist < dist){
                dist = tmp_dist;
            }
        }
        candidate.insert(cur);
    }
    cout << dist << "\n";
    
    return 0;

}

