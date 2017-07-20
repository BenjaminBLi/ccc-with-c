#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;

int n, p[20], r[20], d[20], memo[1<<20][20];
vector<int> adj[20];

/*
11
-1 20 12
0 11 9
0 12 9
4 15 15
0 6 4
2 8 5
4 22 8
10 9 7
4 8 1
1 3 0
1 12 8
 */

int solve(int mask, int u){
    if(mask == ((1<<n)-1))
        return r[u];

    if(memo[mask][u] != -1) return memo[mask][u];
    int best = 20000;
    for(int i = 1; i < n; i++){
        if((mask & (1<<i)) || (mask & (1 << p[i])) == 0) continue;
        best = min(best, max(r[u], d[u] + solve(mask | (1<<i), i)));
    }
    memo[mask][u] = best;
    return best;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", p+i, r+i, d+i);
        if(p[i] != -1) adj[p[i]].push_back(i);
    }
    memset(memo, -1, sizeof(memo));
    int ans = solve(1, 0);
    printf("%d\n", ans);

    return 0;
}
