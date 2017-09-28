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
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, S, p[100010], memo[100010], dep[100010], cnt[100010], st1, st2, t;
vi adj[100010], tree[100010];

void root(int u, int pre){
    for(int v : adj[u]){
        if(v == pre) continue;
        p[v] = u;
        tree[u].pb(v);
        dep[v] = dep[u]+1;
        root(v, u);
    }
}
void dfs(int u, int v) {
    if(u == v){
        if(u != t) cnt[u] += abs(dep[t]-dep[u]);
        return;
    }
    if(dep[u] > dep[v]){
        cnt[u] += abs(dep[t]-dep[u]);
        dfs(p[u], v);
    }else{
        cnt[v] += abs(dep[t] - dep[v]);
        dfs(u, p[v]);
    }
}

int main(){
    scanf("%d %d", &n, &S);
    fori(i, 1, n){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].pb(v), adj[v].pb(u);
    }
    p[1] = 0;
    dep[1] = 1;
    root(1, -1);
    fori(st, 0, S){
        scanf("%d %d %d", &st1, &st2, &t);
        dfs(st1, st2);
    }
    fori(i, 1, n+1) printf("%d ", cnt[i]);

    return 0;
}
