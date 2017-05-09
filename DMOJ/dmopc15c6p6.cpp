#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N, M, K;
bitset<1510> adj[1510], tmp[1510];

void selfMultiply(){
    for(int i = 1; i <= N; i++){
        for(int j = 1;j <= N; j++){
            adj[i].set((size_t) j, adj[j].count() != 0);
        }
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &K);
    for(int i =0;i < M; i++){
        int u, v; scanf("%d %d", &u, &v);
        adj[u].set((size_t) v, true); adj[v].set((size_t) u, true);
    }
    for(int i = 0; i < K; i++) {
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++) printf("%d, ", adj[i][j] ? 1 : 0);
            printf("\n");
        }printf("\n");
        selfMultiply();
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) printf("%d, ", adj[i][j] ? 1 : 0);
        printf("\n");
    }


    return 0;
}
