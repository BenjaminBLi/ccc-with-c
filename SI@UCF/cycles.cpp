#include "bits/stdc++.h"
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
/*
 * centroid decomposition
 * store all "paths" in a sequence - red edges = -1, blue edges = +1
 * look for paths that end up being -1/+1 at the end
 * take a data structure to keep track of the information and pair it with everything you're currently looking at
 *  use a "frequency table" - array to solve everything

6
1 2 r
2 3 b
2 4 r
4 6 b
4 5 b
 */

int n, p[100010], sz[100010], freq[2000010], offset;
vii adj[100010];
queue<int> q;
vi path;
bool blocked[100010];

void findPaths(int u, int p, int sum) {
    path.pb(sum);

    for (ii &e : adj[u]) {
        int v = e.f;
        if (v == p || blocked[v]) continue;
        findPaths(v, u, e.s + sum);
    }
}

ll  solveSub(int u, int sz){
    for(int i = offset-sz; i <= offset+sz; i++)
        freq[i] = 0;

    ll res = 0;
    for(ii &e : adj[u]) {
        int v = e.f;
        if (blocked[v]) continue;
        path.clear();
        findPaths(v, u, e.s);
        for (int pt : path) {
            if(pt == -1 || pt == 1) res++;
            res += freq[offset + (-pt + 1)];
            res += freq[offset + (-pt - 1)];
        }
        for(int pt : path) {
            freq[offset + pt]++;
        }
    }

    return res;
}

void findSz(int u, int pre){
    p[u] = pre;
    sz[u] = 1;
    for(ii e : adj[u]){
        int v = e.f;
        if(v == pre || blocked[v]) continue;
        findSz(v, u);
        sz[u] += sz[v];
    }
}

ll solve(int st){
    findSz(st, st);
    int ct = st;
    int bestSz = sz[st];

    int compSz = 0;
    q.push(st);

    while(q.size()){
        int u = q.front(); q.pop();
        compSz++;
        int cSz = sz[st] - sz[u];

        for(ii e : adj[u]){
            int v = e.f;
            if(v != p[u] && !blocked[v]){
                if(cSz < sz[v]) cSz = sz[v];
                q.push(v);
            }
        }
        if(cSz < bestSz){
            ct = u;
            bestSz = cSz;
        }
    }

    ll ans = solveSub(ct, compSz);
    blocked[ct] = true;
    for(ii e : adj[ct])
        if(!blocked[e.f])
            ans += solve(e.f);

    return ans;
}

int main(){
    scanf("%d", &n);
    offset = n;
    int a, b;
    char ch;
    for(int i = 1; i < n; i++){
        scanf("%d %d %c", &a, &b, &ch);
        adj[a].pb(ii(b, ch == 'b' ? 1 : -1));
        adj[b].pb(ii(a, ch == 'b' ? 1 : -1));
    }

    ll ans = solve(1);
    printf("%lld\n", ans - (n-1));

    return 0;
}
