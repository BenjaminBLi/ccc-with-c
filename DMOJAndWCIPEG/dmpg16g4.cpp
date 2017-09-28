#include <bits/stdc++.h>
using namespace std;

int N, M, memo[2][100010], last[100010], id[100010], delay[100010];

int main(){
    scanf("%d %d", &N, &M);
    for(int i = N;i > 0; i--) scanf("%d", id+i);
    for(int i = 1;i <= M; i++) scanf("%d", delay+i);

    memo[1][1] = 1, last[id[1]] = 1;

    for(int i = 2;i <= N; i++) {
        memo[0][i] = max(memo[0][i-1], memo[1][i-1]);
        memo[1][i] = memo[1][last[id[i]]];

        if(id[i] == id[i-1]) memo[1][i] = memo[1][i-1];

        int lIdx = max(0, i - 1 - delay[id[i]]);
        memo[1][i] = max(memo[1][i], max(memo[1][last[id[i]]], max(memo[0][lIdx], memo[1][lIdx])))+1;

        last[id[i]] = i;
    }

    //for(int i = 1; i <= N; i++) printf("%d, ", memo[0][i]); cout << endl;
    //for(int i = 1; i <= N; ++i) printf("%d, ", memo[1][i]); cout << endl; cout << endl;
    //for(int i = 1; i <= M; i++) printf("%d, ", last[i]); cout << endl;

    printf("%d\n", max(memo[0][N], memo[1][N]));

    return 0;
}