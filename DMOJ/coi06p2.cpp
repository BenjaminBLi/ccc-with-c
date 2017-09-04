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

int N, E, cIdx = 0, Q, low[100010], dfn[100010], en[100010], lca[19][100010], dep[100010], p[100010];
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
            dep[v] = dep[u]+1;
            lca[0][v]=v;
            for(int j = 1; j < 19; j++){
                if(lca[j-1][v] != -1)
                    lca[j][v] = lca[j-1][lca[j-1][v]];
                else break;
            }
            dfs(v);
            if(low[u] > low[v]) low[u] = low[v];
        }else if(low[u] > dfn[v]) low[u] = dfn[v];
    }
    en[u] = cIdx;
}

bool inTree(int &u, int &v){return dfn[u] >= dfn[v] && en[u] <= en[v];}

int search(int x, int y){
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = 18; i >= 0; i--)
        if(dep[x] >= dep[y] + (1<<i)) x = lca[i][x];
    if (x== y) return y;
    for(int i = 18; i >= 0; i--)
        if(lca[i][x] != -1 && lca[i][x] != lca[i][y])
            x = lca[i][x], y = lca[i][y];
    return lca[0][x];
}

int main(){
    memset(lca, -1, sizeof(lca));
    scanf("%d %d", &N, &E);
    fori(i, 0, E){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].pb(i), adj[v].pb(i);
        id[i] = ii(u, v);
    }
    dep[1] = 0;
    dfs(1);
    scanf("%d", &Q);
    int t, a, b, u, v, c;
    bool ia, ib;
    fori(q, 0, Q){
        scanf("%d", &t);
        if(t == 1){
            scanf("%d %d %d %d", &a, &b, &u, &v);
            if(dfn[u] > dfn[v]) swap(u, v);
            ia = inTree(a, v), ib = inTree(b, v);
            if(low[v] <= dfn[u] || ia == ib) printf("yes\n");
            else printf("no\n");
        }else{
            scanf("%d %d %d", &a, &b, &c);
            printf("no\n");
        }
    }

    return 0;
}