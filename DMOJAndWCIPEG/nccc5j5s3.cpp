#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) (en); i++)
#define rfori(i, st, en) for(int i = st; i >= (int) (en); i--)
#define f first
#define s second
#define pb push_back
#define left(i) (i<<1)
#define right(i) (i<<1|1)
#define mid(l, r) ((l+r)>>1)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef double lf;

const int MAXN = 60;
int n, m, rnk[MAXN];
bool ok[100010], vis[MAXN];
vi adj[MAXN];
ii es[100010];

void init(){fori(i, 0, MAXN) rnk[i] = -1;}
int fs(int u){return rnk[u] < 0 ? u : rnk[u] = fs(rnk[u]);}
bool us(int u, int v){
    if((u = fs(u)) != (v = fs(v))){
        if(rnk[u] > rnk[v]) swap(u, v);
        rnk[u] += rnk[v];
        rnk[v] = u;
        return true;
    }
    return false;
}

void reset(){
    fori(i, 0, MAXN) vis[i] = false;
}

void dfs(int u){
    vis[u] = true;
    for(int i : adj[u])
        if(!ok[i] && !vis[es[i].s]) dfs(es[i].s);
}

int main(){
    init();
    scanf("%d%d", &n, &m);
    fori(i, 0, m) {
        scanf("%d%d", &es[i].f, &es[i].s);
        adj[es[i].f].pb(i);
    }

    fori(i, 0, m){
        reset();
        ok[i] = true;
        dfs(1);
        ok[i] = false;
        if(vis[n]) puts("YES");
        else puts("NO");
    }

    return 0;
}

