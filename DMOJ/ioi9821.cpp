#include <bits/stdc++.h>
using namespace std;

struct rect{short x1, x2, y1, y2;} r[5000];
map<short, short> compx, compy;
unsigned short diff[5001][5001];
short n, r1, r2, c1, c2;
vector<int> xs, ys;

int area(int change){
    memset(diff, 0, sizeof(diff));
    compx.clear(); compy.clear(); xs.clear(); ys.clear();
    for(int i = 0; i < n; i++){
        compx[r[i].x1+change] = compx[r[i].x2-change] = 0;
        compy[r[i].y1+change] = compy[r[i].y2-change] = 0;
    }

    short cntx = 1, cnty = 1;
    for(auto &it : compx){xs.push_back(it.first); it.second = cntx++;};
    for(auto &it : compy){ys.push_back(it.first); it.second = cnty++;};

    for(int i = 0; i < n; i++){
        r1 = compx[r[i].x1+change], r1 = compx[r[i].x2-change];
        c1 = compy[r[i].y1+change], c2 = compy[r[i].y2-change];
        diff[r1][c1]++; diff[r1][c2]--;diff[r2][c1]--;diff[r2][c2];
    }

    int ans = 0;
    for(int i = 1; i < xs.size(); i++){
        for(int j = 1; j < ys.size(); j++){
            diff[i][j] += diff[i-1][j] + diff[i][j-1] - diff[i-1][j-1];
            if(diff[i][j]) ans += (xs[i] - xs[i - 1])*(ys[j] - ys[j - 1]);
        }
    }
    return ans;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d %d %d", &r[i].x1, &r[i].y1, &r[i].x2, &r[i].y2);
    printf("%d", (area(0)-area(1)));
    return 0;
}
