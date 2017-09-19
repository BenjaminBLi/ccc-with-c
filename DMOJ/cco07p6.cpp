#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N, M, cIdx = 0, cnt = 0, cRoot;
int stk[1010], low[1010], dfn[1010], ecnt[1010];
map<int, ii> id;
bool vis[1010], isB[1010], art[1010];
vi adj[1010], meta[1010];

int findO(int u, ii e){
    if(e.first == u) return e.second;
    return e.first;
}

void dfs(int u) {
    low[u] = dfn[u] = ++cIdx;
    for (int j : adj[u]) {
        int v = findO(u, id[j]);
        if(vis[j]) continue;
        stk[++stk[0]] = j;
        vis[j] = true;
        if (dfn[v] == 0) {
            dfs(v);
            if(low[u] > low[v]) low[u] = low[v];
            if (low[v] > dfn[u])
                isB[j] = true;
        } else if (low[u] > dfn[v]) low[u] = dfn[v];
    }
}

int main(){
    scanf("%d %d", &N, &M);
    fori(i, 0, M){
        int u, v;
        scanf("%d %d", &u, &v);
        id[i] = ii(u, v);
        adj[u].pb(i);
        adj[v].pb(i);
    }
    fori(i, 1, N+1)
        if(dfn[i] == 0) {
            dfs(i);
        }
    int ans = 0;
    fori(i, 1, N+1){
        for(int e : adj[i]){
            int v = findO(i, id[e]);
            if(low[v] != low[i]) ecnt[low[i]]++;
        }
    }
    fori(i, 1, N+1) if(ecnt[i] == 1) ans++;
    printf("%d\n", (ans)/2 + ans%2);

    return 0;
}