#include "bits/stdc++.h"
#define ii pair<int, int>
#define f first
#define s second
using namespace std;

struct event{
    int x, top, bot, val;
    event(){};
    event(int a, int b, int c, int d){
        x = a, bot = b, top = c, val = d;
    }
} events[200010];

bool comp(event a, event b){
    return a.x < b.x;
}

int N, M;
int diff[8110][8010], sum[8110];
ii magnet[4010];

/*
 * 0 4000 4031 1
 * 30 4000 4031 -1
 * 27 3986 4013 1
 * 54 3986 4013 -1
 * 31 3996 4037 1
 * 72 3996 4037 -1
 *
 * 15
 * 20
 * 13
 */

void rotate(int &x, int &y){
    int tx = x, ty = y;
    x = tx+ty;
    y = ty-tx+4001;
}

int calcDist(ii &a, ii &b){
    return abs(a.f-b.f) + abs(a.s-b.s);
}

int main(){
    scanf("%d", &M);
    for(int i = 0; i < M; i++)
        scanf("%d %d", &magnet[i].f, &magnet[i].s);

    scanf("%d", &N);
    ii curr;
    for(int i = 0; i < N; i++){
        scanf("%d %d", &curr.f, &curr.s);
        int c = (int)1e9;
        for(int j = 0; j < M; j++) c = min(c, calcDist(curr, magnet[j]));
        if(--c <= 0) continue;

        rotate(curr.f, curr.s);

        int x = curr.f, y = curr.s;
        int x1 = max(0, x-c), x2 = min(8001, x+c+1);
        int y1 = max(0, y-c), y2 = min(8001, y+c+1);

        diff[x1][y1]++;
        diff[x1][y2]--;
        diff[x2][y1]--;
        diff[x2][y2]++;
    }
    int ans = 0;
    for(int i = 0; i < 8002; i++){
        for(int j = 0; j < 8002; j++){
            if(i) diff[i][j] += diff[i-1][j];
            if(j) diff[i][j] += diff[i][j-1];
            if(i > 0 && j > 0) diff[i][j] -= diff[i-1][j-1];
            ans = max(ans, diff[i][j]);
        }
    }

    printf("%d\n", ans);

    return 0;
}