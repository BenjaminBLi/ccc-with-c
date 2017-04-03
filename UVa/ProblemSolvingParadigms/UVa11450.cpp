#include <bits/stdc++.h>
using namespace std;

int N, M, C, arr[20][20], K[20], memo[201][20];

int solve(int idx, int curr){
    if(idx == C) return curr;
    if(memo[curr][idx] != -1) return memo[curr][idx];
    int best = 0;
    for(int i =0; i < K[idx]; i++){
        if(curr+arr[idx][i] <= M)
            best = max(best, solve(idx+1, curr+arr[idx][i]));
    }
    return memo[curr][idx] = best;
}

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d", &N);
    for(;N--;){
        scanf("%d %d", &M, &C);
        memset(memo, -1, sizeof(memo));
        for(int i =0; i < C; i++){
            scanf("%d", &K[i]);
            for(int j = 0; j < K[i]; j++) scanf("%d", &arr[i][j]);
        }
        int done = solve(0, 0);
        if(done) printf("%d\n", done);
        else printf("no solution\n");
    }
    return 0;
}
