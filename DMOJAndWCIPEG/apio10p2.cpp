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

int N, K, bV, maxH, sz, st, p[100010], maxD = 0;
ii memo[100010];
vi adj[100010];
map<int, int> w[100010];
bool vis[100010];

void diam(int u){
    sz++;
    vis[u] = true;
    for(int v : adj[u]) {
        if(vis[v]) continue;
        p[v] = u;
        diam(v);
    }
    sz--;
    if(sz > maxH){
        maxH = sz;
        bV = u;
    }
}

void change(){
    fori(u, 1, N+1)
        for(int v : adj[u])
            w[u][v] = w[v][u] = 1;
    for(int u = bV; u != st; u = p[u])
        w[u][p[u]] = w[p[u]][u] = -1;
}

void solve(int u) {
    vis[u] = true;
    int bst = 0, tbst = 0;
    for (int v : adj[u]) {
        if (vis[v]) continue;
        solve(v);
        int val = w[u][v];
        if (bst <= memo[v].f+val) {
            tbst = bst;
            bst = memo[v].f+val;
        } else if (tbst <= memo[v].f+val) tbst = val+memo[v].f;
    }
    memo[u] = {bst, tbst};
    maxD = max(maxD, bst+tbst);
}

int main() {
    scanf("%d %d", &N, &K);
    fori(i, 1, N) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].pb(v), adj[v].pb(u);
    }
    bV = 1, maxH = 0, sz = 0;
    memset(vis, false, sizeof(vis));
    diam(1);
    memset(vis, false, sizeof(vis));
    sz = 0, maxH = 0, st = bV;
    diam(bV);
    if (K == 1) {
        printf("%d\n", 2 * (N - 1) - maxH + 1);
    } else {
        fori(i, 0, N + 1) vis[i] = false;
        change(), solve(1);
        printf("%d\n", 2 * (N - 1) - maxH + 2 - maxD);
    }

    return 0;
}
