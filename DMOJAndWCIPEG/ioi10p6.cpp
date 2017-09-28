#include <bits/stdc++.h>
using namespace std;
int tot, w[1000010], dst[1000010];
bool vis[1000010];
vector<int> adj[1000010];

int dfs(int u){
    int bst = 0, rem = 0, tmp = 0;
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]){
            tmp = dfs(v);
            if(bst < tmp) bst = tmp;
            rem += tmp;
        }
    }
    dst[u] = max(bst, tot-rem-w[u]);
    return rem + w[u];
}

int LocateCentre(int N, int P[], int S[], int D[]){
    tot = 0;
    for(int i = 0; i < N; i++) {
        tot += P[i];
        w[i] = P[i];
    }
    for(int i = 0; i < N-1; i++){
        adj[S[i]].push_back(D[i]);
        adj[D[i]].push_back(S[i]);
    }
    dfs(1);
    int bst = dst[0], bIdx = 0;
    for(int i = 1; i < N; i++){
        if(bst > dst[i]) bst = dst[i], bIdx = i;
    }
    return bIdx;

    return 0;
}