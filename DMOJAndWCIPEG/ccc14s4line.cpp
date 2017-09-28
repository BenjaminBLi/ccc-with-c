#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int N, T, ys[2010], idx, idxy, x1, x2, ya, yb, len, st, en;
ll ctnt;
struct line{
    int x, y1, y2;
    ll val;
    line(){};
    line(int a, int b, int c, ll tnt){
        x = a, y1 = b, y2 = c, val = tnt;
    }
};
line events[2010];
ll ans, cTint[2010];

bool comp(line a, line b){
    return a.x < b.x;
}
int search(int y){
    int lo = 1, hi = len, mid;
    while(lo < hi){
        mid = (lo+hi)/2;
        if(ys[mid] >= y) hi = mid;
        else lo = mid+1;
    }
    return lo;
}

int main(){
    scanf("%d%d", &N, &T);
    idx = idxy = 1;
    for(int i = 0; i < N; i++){
        scanf("%d %d %d %d %lld", &x1, &ya, &x2, &yb, &ctnt);
        events[idx++] = line(x1, ya, yb, ctnt);
        events[idx++] = line(x2, ya, yb, -ctnt);
        ys[idxy++] = ya;
        ys[idxy++] = yb;
    }
    sort(events+1, events+idx, comp);
    sort(ys+1, ys+idxy);
    len = (int) (unique(ys+1, ys+idxy) - (ys+1));
    ans = 0;
    for(int i = 1; i < idx; i++){
        for(int j = 1; j < len; j++){
            if(cTint[j] >= T){
                ans += (ll)(ys[j+1]-ys[j])*(events[i].x-events[i-1].x);
            }
        }
        st = search(events[i].y1), en = search(events[i].y2);
        for(int j = st; j < en; j++) cTint[j] += events[i].val;
    }
    printf("%lld\n", ans);
    return 0;
}
