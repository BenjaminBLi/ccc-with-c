#include "bits/stdc++.h"
using namespace std;

int T, N, ts, te, s[20], f[20], d[20], memo[20][5010];

int solve(int idx, int time) {
    if (time > te) return -10000010;
    if (idx == N - 1) {
        return 0;
    }

    int best = -10000010;

    if (time <= s[idx]) best = max(best, solve(idx + 1, s[idx] + d[idx]));
    else {
        int c = s[idx];
        while (c < time) c += f[idx];
        best = max(best, solve(idx + 1, c + d[idx]));
    }
    time += ts;
    if (time <= s[idx]) best = max(best, 1 + solve(idx + 1, s[idx] + d[idx]));
    else {
        int c = s[idx];
        while (c < time) c += f[idx];
        best = max(best, 1 + solve(idx + 1, c + d[idx]));
    }
    return memo[idx][time] = best;
}

int main(){
    freopen("C:\\Users\\strik\\CLionProjects\\ccc-with-c\\CodeJam\\in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        scanf("%d %d %d", &N, &ts, &te);
        printf("Case #%d: ", t);
        for(int i = 0; i < N-1; i++) scanf("%d %d %d", s+i, f+i, d+i);
        int ans = solve(0, 0);
        if(ans <= -1) printf("IMPOSSIBLE\n");
        else printf("%d\n", ans);
    }

    return 0;
}
