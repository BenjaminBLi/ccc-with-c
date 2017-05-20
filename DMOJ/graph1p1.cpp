#include <bits/stdc++.h>
using namespace std;

int adj[110][110], tmp[110][110], res[110][110], N, K;

void selfMultiply(){
    memcpy(tmp, res, sizeof(res));
    memset(res, 0, sizeof(res));
    for(int i = 0; i < N; i++){
        for(int j = 0;j < N; j++){
            for(int k = 0;k < N; k++){
                res[i][j] += tmp[i][k]*adj[k][j];
            }
        }
    }
}

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0;i < N; i++) for(int j = 0;j < N; j++) {
            scanf("%d", &adj[i][j]);
            res[i][j] = adj[i][j];
    }
    for(int i = 1; i < K; i++) selfMultiply();
    int cnt = 0;
    for(int i = 0;i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d, ", res[i][j] > 0 ? 1 : 0);
            cnt += res[i][j];
        }
        printf("\n");
    }
    printf("%d\n", cnt);

    return 0;
}
