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

int n, E, cIdx = 0, Q, low[100010], dfn[100010], en[100010], lca[19][100010], dep[100010], p[100010];
map<int, ii> id;
vi adj[100010];
bool vis[500010];

int findo(int u, ii e){
    if(e.f == u) return e.s;
    return e.f;
}

void dfs(int u){
    low[u] = dfn[u] = en[u] = ++cIdx;
    for(int e : adj[u]){
        int v = findo(u, id[e]);
        if(vis[e]) continue;
        vis[e] = true;
        if(dfn[v] == 0){
            p[v] = u;
            lca[0][v] = u;
            dep[v] = dep[u]+1;
            dfs(v);
            if(low[u] > low[v]) low[u] = low[v];
        }else if(low[u] > dfn[v]) low[u] = dfn[v];
    }
    en[u] = cIdx;
}

bool inTree(int &u, int &v){return dfn[u] >= dfn[v] && en[u] <= en[v];}

void genTable() {
    fori(i, 1, 19)
        fori(u, 1, n + 1)
            lca[i][u] = lca[i - 1][lca[i - 1][u]];
}

int getp(int u, int dst) {
    int cv = u, i = 17;
    while(dst){
        if(dst >= (1<<i)){
            cv = lca[i][cv];
            dst -= (1<<i);
        }else i--;
    }
    return cv;
}

int main() {
    memset(lca, -1, sizeof(lca));
    scanf("%d %d", &n, &E);
    fori(i, 0, E) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].pb(i), adj[v].pb(i);
        id[i] = ii(u, v);
    }
    fori(i, 1, n+1){
        if(dfn[i] == 0){
            dep[i] = 0;
            dfs(i);
        }
    }
    genTable();

    scanf("%d", &Q);
    int t, a, b, u, v, c;
    bool ia, ib;
    fori(q, 0, Q) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d %d %d %d", &a, &b, &u, &v);
            if (dfn[u] > dfn[v]) swap(u, v);
            ia = inTree(a, v), ib = inTree(b, v);
            if (low[v] <= dfn[u] || ia == ib) printf("yes\n");
            else printf("no\n");
        } else {
            scanf("%d %d %d", &a, &b, &c);
            ia = inTree(a, c), ib = inTree(b, c);
            if (!ia && !ib) printf("yes\n");
            else if (ia && ib) {
                int d = getp(a, dep[a] - dep[c] - 1), e = getp(b, dep[b] - dep[c] - 1);
                if (d == e || (low[d] < dfn[c] && low[e] < dfn[c])) printf("yes\n");
                else printf("no\n");
            } else if (ia) {
                int d = getp(a, dep[a] - dep[c] - 1);
                if (low[d] < dfn[c]) printf("yes\n");
                else printf("no\n");
            } else {
                int d = getp(b, dep[b] - dep[c] - 1);
                if (low[d] < dfn[c]) printf("yes\n");
                else printf("no\n");
            }
        }
    }
    return 0;
}
