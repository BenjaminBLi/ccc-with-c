#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;

int N, M, grid[110][110], dr[4] = {1, -1, 0,0}, dc[4] = {0, 0, 1, -1};
bool vis[110][110];
queue<ii> q;

void reset(){
    fori(i, 0, M)
        fori(j, 0, N)
            vis[i][j] = false;
    while(q.size())
        q.pop();
}

bool valid(int r, int c, int mask) {
    if (r < 0 || c < 0 || r >= M || c >= N)
        return false;
    return (mask & (1 << grid[r][c])) != 0;
}

bool bfs(int mask) {
    fori(st, 0, N) {
        reset();
        if (!valid(0, st, mask)) continue;
        q.push(ii(0, st));
        vis[0][st] = true;
        ii u;
        while (q.size()) {
            u = q.front();
            q.pop();
            int r = u.f, c = u.s;
            if (r == M-1) return true;
            fori(i, 0, 4) {
                int nr = r+dr[i], nc = c+dc[i];
                if (!valid(nr, nc, mask) || vis[nr][nc]) continue;
                vis[nr][nc] = true;
                q.push(ii(nr, nc));
            }
        }
    }
    return false;
}

void printMask(int mask){
    if(mask == -1) {
        printf("-1 -1 -1\n");
        return;
    }
    vector<int> des;
    des.assign(3, 0);
    int idx = 2;
    rfori(i, 9, 0){
        if(mask & (1<<i))
            des[idx--] = i;
    }
    for(int v : des)
        printf("%d ", v);
}

int conv(int st) {
    int ret = 0;
    fori(i, 0, 3){
        ret |= (1 << (st % 10));
        st /= 10;
    }
    return ret;
}

int main(){
    scanf("%d %d", &N, &M);
    fori(r, 0, M)
        fori(c, 0, N)
            scanf("%d", &grid[r][c]);

    int mask = -1;
    for(int i = 0; i < 1000; i++){
        if(bfs(conv(i))){
            mask = conv(i);
            break;
        }
    }
    printMask(mask);
    return 0;
}
