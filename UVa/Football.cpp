#include <bits/stdc++.h>
#define MAXN 300
#define fori(i, n) for(int i = 0, _n = n; i < _n; i++)
using namespace std;
typedef pair<int, int> ii;
using namespace std;

int W, H, N, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, f[MAXN][4], tx[MAXN], ty[MAXN];
bool done = false;

bool bounded(int x, int y){
    return x > 0 && y > 0 && x <= W && y <= H;
}

bool check(int x, int y, int i){
    return x >= f[i][0] && x <= f[i][2] && y >= f[i][1] && y <= f[i][3];
}

void dfs(int fn){
    if(done) return;
    if(fn == N){
        fori(i, N) printf("%d %d", tx[i], ty[i]);
        done = true; return;
    }
    fori(i, 4){
        int cx = tx[fn-1] + dx[i], cy = ty[fn-1]+dy[i];
        bool ok = !check(cx, cy, fn);
        if(bounded(cx, cy) && ok){
            tx[fn] = cx; ty[fn] = cy;
            dfs(fn+1);
            tx[fn] = 0; ty[fn] = 0;
            if(done) return;
        }
    }
}

int main(){
    freopen("broadcast.in", "r", stdin);
    freopen("broadcast.out", "w", stdout);
    scanf("%d %d %d", &W, &H, &N);
    fori(i, N) scanf("%d %d %d %d", &f[i][0], &f[i][1], &f[i][2], &f[i][3]);
    for(int i = 1; i <= W; i++){
        for(int j = 1; j <= H; j++){
            if(!check(i, j, 0)){
                memset(tx, 0, sizeof(tx)); memset(ty, 0, sizeof(ty));
                tx[0] = i; ty[0] = j; dfs(1);
                if(done) break;
            }
        }
        if(done) break;
    }
    if(!done) printf("Impossible\n");
    return 0;
}
