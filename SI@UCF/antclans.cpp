#include "bits/stdc++.h"
#define MAXN 1<<20
#define INF 2e10
using namespace std;
typedef long long ll;

int n, m, k, nS;
ll adj[30][30], lookup[MAXN], val[MAXN], memo[MAXN];
bool st[MAXN];

int highestOneBit(int i) {
    i |= (i >>  1);
    i |= (i >>  2);
    i |= (i >>  4);
    i |= (i >>  8);
    i |= (i >> 16);
    return i - ((unsigned) i >> 1);
}

int lg(int v){
    int r = 0;
    while(v >>= 1) {
        r++;
    }
    return r;
}

void gen(){
    for (int mask = 0; mask < nS; mask++) {
        lookup[mask] = INF;
        memo[mask] = -1;
        if (__builtin_popcount(mask) != k) continue;
        for(int i = 0; i < n; i++) val[i] = INF, st[i] = false;
        int u = lg(mask);
        val[u] = 0;
        ll sum = 0;
        for(int i = 0; i < __builtin_popcount(mask); i++){
            int j = -1;
            for(int k = 0; k < n; k++)
                if(!st[k] && (mask & (1<<k)) && (j == -1 || val[k] < val[j]))
                    j = k;

            if(val[j] == INF){
                sum = INF;
                break;
            }
            st[j] = true;
            sum += val[j];
            for(int k = 0; k < n; k++) if(!st[k] && adj[j][k] < val[k]) val[k] = adj[j][k];
        }
        lookup[mask] = min(sum, (ll) INF);
    }
}

ll solve(int mask) {
    if (__builtin_popcount(mask) == k)
        return lookup[mask];

    if(memo[mask] != -1) return memo[mask];
    ll tot = INF;
    int lBit = highestOneBit(mask);
    for (int cMask = mask; cMask; cMask = (cMask-1)&mask) {
        if(((cMask)&lBit) == 0) break;
        if(__builtin_popcount(cMask) != k || lookup[cMask] == INF) continue;
        ll tmp;
        tmp = solve(mask^cMask);
        if(tmp == INF) continue;
        if(tot > lookup[cMask]+tmp) tot = lookup[cMask]+tmp;
    }
    memo[mask] = tot;
    return tot;
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) adj[i][j] = INF;
    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        scanf("%d %d %lld", &u, &v, &w);
        u--;
        v--;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    nS = 1<<n;
    if(n%k != 0) printf("-1\n");
    else {
        k = n/k;
        gen();
        ll ans = solve(nS - 1);
        if (ans >= INF) printf("-1\n");
        else printf("%lld\n", ans);
    }
    return 0;
}
