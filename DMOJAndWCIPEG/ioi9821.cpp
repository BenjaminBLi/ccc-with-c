#include <bits/stdc++.h>
using namespace std;

int N, xCnt, yCnt;
struct rect{
    int x1, y1, x2, y2;
} r[5000];

map<int, int> cx, cy, rx, ry;
void getInput(){
    scanf("%d", &N);
    xCnt = yCnt = 0;
    for(int i = 0; i < N; i++){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        cx[x1] = cx[x2] = 0;
        cy[y2] = cy[y1] = 0;
    }
    for(auto &it : cx) it.second = xCnt, rx[xCnt++] = it.first;
    for(auto &it : cy) it.second = yCnt, ry[yCnt++] = it.first;
}

int main(){
    getInput();

    return 0;
}
