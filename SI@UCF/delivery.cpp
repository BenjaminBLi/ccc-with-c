#include <bits/stdc++.h>
using namespace std;

int N, M, adj[510][510], memo[510][510];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) scanf("%d", &adj[i][j]), memo[i][j] = adj[i][j];
    for(int k = 0; k < N; k++) for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
                if(adj[i][j] == -1 || adj[i][k] == -1 || adj[k][j] == -1) continue;
                if(memo[i][k] + memo[k][j] < memo[i][j]){
                    memo[i][j] = memo[i][k] + memo[k][j];
                }
            }

    printf("%d\n", memo[0][N-1]);

    return 0;
}
