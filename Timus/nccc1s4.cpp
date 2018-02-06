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

const int MAXN = 1010;
struct edge{
    int v, c, d;
};

int n, m, K, s, t;
vector<edge> adj[MAXN];
bitset<MAXN> vis;

void dfs(int u, int val){
    vis[u] = true;
    for(edge e : adj[u])
        if(!vis[e.v] && e.c <= val && val <= e.d) 
            dfs(e.v, val);
}

int main(){
    scanf("%d%d%d", &n, &m, &K);
    scanf("%d%d", &s, &t);
    vi vals;
    fori(i, 0, m){
        edge c;
        int u;
        scanf("%d%d%d%d", &u, &c.v, &c.c, &c.d);
        vals.pb(c.c);
        vals.pb(c.d+1);
        adj[u].pb(c);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int ans = 0;
    fori(i, 0, vals.size()-1){
        vis.reset();
        dfs(s, vals[i]);
        if(vis[t]) ans += vals[i+1]-vals[i];
    }

    cout << ans << endl;

    return 0;
}

