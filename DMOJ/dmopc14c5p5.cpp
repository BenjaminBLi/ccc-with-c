#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int N, M;

map<int, int> adj[100010];
ll memo[100010];
bool visited[100010];
ll solve(int u){

    ll tDist = 0;

    return memo[u] = tDist;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
    }
    memset(memo, -1, sizeof(memo));

    for(int i = 2; i <= N; i++){
        printf("%d %d\n", adj[i].size(), solve(i));
    }

    return 0;
}
