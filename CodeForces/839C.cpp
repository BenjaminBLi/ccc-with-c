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

int n;
vi adj[100010], tree[100010];
double memo[100010];
bool vis[100010];

void root(){
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(!vis[v]) {
                tree[u].pb(v);
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

double solve(int u){
    if(tree[u].empty())
        return 0;

    if(memo[u] != -1) return memo[u];
    double val = 0, cnt = 0;
    for(int v : tree[u]){
        val += 1 + solve(v);
        cnt++;
    }
    val /= cnt;
    memo[u] = val;
    return val;
}

int main(){
    scanf("%d", &n);
    fori(i, 1, n){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].pb(v); adj[v].pb(u);
    }
    fill(memo, memo+1+n, -1);
    root();
    printf("%lf\n", solve(1));
    return 0;
}