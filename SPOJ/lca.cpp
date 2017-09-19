#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;

int n, lca[10][1010], dep[1010], p[1010];
vi adj[1010];
bool vis[1010];

int search(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 18; i >= 0; i--)
        if (dep[x] >= dep[y] + (1 << i)) x = lca[i][x];
    if (x == y) return y;
    for (int i = 18; i >= 0; i--)
        if (lca[i][x] != -1 && lca[i][x] != lca[i][y])
            x = lca[i][x], y = lca[i][y];
    return lca[0][x];
}
void reset() {
    fori(j, 0, 10) fori(i, 1, n + 1) lca[j][i] = -1;
    fori(i, 1, n + 1) adj[i].clear(), vis[i] = false;
}
void root() {
    queue<int> q;
    q.push(1);
    vis[1] = true;
    lca[0][1] = 1;
    fori(j, 1, 10) {
        if (lca[j - 1][1] != -1)
            lca[j][1] = lca[j - 1][lca[j - 1][1]];
        else break;
    }
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int v : adj[u])
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
                p[v] = u;
                lca[0][v] = v;
                fori(j, 1, 10) {
                    if (lca[j - 1][v] != -1)
                        lca[j][v] = lca[j - 1][lca[j - 1][v]];
                    else break;
                }
            }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    fori(t, 1, T+1) {
        scanf("%d", &n);
        printf("Case %d:\n", t);
        reset();
        fori(i, 0, n) {
            int M;
            scanf("%d", &M);
            fori(j, 0, M) {
                int v;
                scanf("%d", &v);
                adj[i].pb(v);
                adj[v].pb(i);
            }
        }
        root();
        int Q;
        scanf("%d",  &Q);
        fori(q, 0, Q){
            int u, v;
            scanf("%d %d", &u, &v);
            printf("%d\n", search(u, v));
        }
    }
    return 0;
}
