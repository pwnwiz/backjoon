// https://www.acmicpc.net/problem/2166
// 다각형의 면적
// Written in C++ langs
// 2020. 06. 11.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Point{
    long long x;
    long long y;
    
    Point(long long x, long long y){
        this->x = x;
        this->y = y;
    }
    
}Point;

int N;

long long ccw(Point a, Point b, Point c){
    return ((b.x - a.x) * (c.y - a.y)) - ((b.y - a.y) * (c.x - a.x));
}

int main(){
    
    cin >> N;
    
    vector<Point> point;
    
    long long x, y;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        point.push_back(Point(x,y));
    }
    
    long long result = 0;
    for(int i=1; i<N-1; i++){
        result += ccw(point[0], point[i], point[i+1]);
    }
    
    result = abs(result);
    
    cout << result/2;
    (result % 2) ? cout << ".5\n" : cout << ".0\n";
    
    return 0;

}

