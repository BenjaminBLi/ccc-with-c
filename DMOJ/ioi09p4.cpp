#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
using namespace std;

int N, M;
int raisins[60][60], memo[60][60][60][60];

inline int cmin(int a, int b){
    return a < b ? a : b;
}

int solve(int sr, int sc, int er, int ec){
    if(memo[sr][sc][er][ec] != 0x3f3f3f3f && memo[sr][sc][er][ec] != -1) return memo[sr][sc][er][ec];
    if(sr == er && sc == ec) return 0;
    int best = 0x3f3f3f3f;
    fori(mr, sr+1, er+1)
        best = cmin(best, solve(sr, sc, mr-1, ec) + solve(mr, sc, er, ec));

    fori(mc, sc+1, ec+1)
        best = cmin(best, solve(sr, sc, er, mc-1) + solve(sr, mc, er, ec));

    best += raisins[er][ec] - raisins[er][sc-1] - raisins[sr-1][ec] + raisins[sr-1][sc-1];

    memo[sr][sc][er][ec] = best;
    return best;
}

int main(){
    scanf("%d %d", &N, &M);
    fori(i, 1, N+1) {
        fori(j, 1, M + 1) {
            scanf("%d", &raisins[i][j]);
            raisins[i][j] += raisins[i][j - 1];
            raisins[i][j] += raisins[i-1][j];
            raisins[i][j] -= raisins[i-1][j-1];
        }
    }

    memset(memo, -1, sizeof(memo));
    printf("%d\n", solve(1, 1, N, M));

    return 0;
}