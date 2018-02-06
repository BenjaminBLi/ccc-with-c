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

const int MAXN = 5010;
struct edge{
    int u, v, w;
    edge(){u = v = w = 0;}
    bool operator < (edge o){
        if(w != o.w) return w > o.w;
        if(u != o.u) return u < o.u;
        return v < o.v;
    }
}es[MAXN]; 
vii adj[MAXN];

int rnk[MAXN];
void init(){fori(i, 0, MAXN) rnk[i] = -1;}
int find(int u){return rnk[u] < 0 ? u : rnk[u] = find(rnk[u]);}
bool us(int u, int v){
    if((u = find(u)) != (v = find(v))){
        if(rnk[u] > rnk[v]) swap(u, v);
        rnk[u] += rnk[v];
        rnk[v] = u;
        return true;
    }
    return false;
}

int n, m, q, a[MAXN];

bool cmp(int a, int b){
    return es[a].w > es[b].w;
}

void gen(){
    init();
    sort(a+1, a+1+m, cmp);
    fori(i, 0, n+1) adj[i].clear();
    fori(i, 1, m+1){
        if(us(es[a[i]].u, es[a[i]].v)){
            adj[es[a[i]].u].pb(ii(es[a[i]].v, es[a[i]].w));
            adj[es[a[i]].v].pb(ii(es[a[i]].u, es[a[i]].w));
        }
    }
}

int t, cw;
bool ok;
void dfs(int u, int p){
    if(ok) return;
    if(u == t) {
        ok = true;
        return ;
    }
    for(ii e : adj[u]){
        if(p == e.f || e.s < cw) continue;
        dfs(e.f, u);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    fori(i, 1, m+1){
        a[i] = i;
        scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].w);
    }

    gen();
    scanf("%d", &q);
    int a, b, id;
    while(q--){
        scanf("%d%d%d", &id, &a, &b);
        if(id == 1){
            es[a].w = b;
            gen();
        }else{
            scanf("%d", &cw);
            ok = false;
            t = b;
            dfs(a, a);
            printf("%d\n", ok);
        }
    }
    return 0;
}

