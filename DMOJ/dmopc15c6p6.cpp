#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int N, M, K;
bitset<1510> adj[1510], tmp[1510], res[1510];

void selfMultiply(){
    for(int i = 1; i <= N; i++){
        tmp[i] = res[i];
        res[i] = bitset<1510>();
        for(int j = 1;j <= N; j++){
            for(int k = 1; k <= N; k++){
                res[i].set(j, res[i][j] || (tmp[i][k]&&adj[k][j]));
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &K);
    for(int i =0;i < M; i++){
        int u, v; scanf("%d %d", &u, &v);
        adj[u].set((size_t) v, true); adj[v].set((size_t) u, true);
        res[u].set((size_t)v, true); res[v].set((size_t)u, true);
    }
    for(int i = 1; i < K; i++) {
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++) printf("%d, ", res[i][j] ? 1 : 0);
            printf("\n");
        }printf("\n");
        selfMultiply();
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) printf("%d, ", res[i][j] ? 1 : 0);
        printf("\n");
    }


    return 0;
}
