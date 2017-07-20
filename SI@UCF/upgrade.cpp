#include "bits/stdc++.h"
using namespace std;
typedef vector<int> vi;

int n, p[100010], depth[100010], idx[100010];
vi adj[100010], levels[100010];

void dfs(int u, int pre){
    depth[u] = depth[pre]+1;
    for(int v : adj[u]){
        idx[v] = levels[depth[u]+1].size();
        levels[depth[u]+1].push_back(v);
    }
    for(int v : adj[u]){
        dfs(v, u);
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 2; i <= n; i++){
        scanf("%d", p+i);
        adj[p[i]].push_back(i);
    }

    dfs(1, 0);


    printf("-1");
    for(int i = 2; i <= n; i++){
        if(idx[i]) printf(" %d", levels[depth[i]][idx[i]-1]);
        else printf(" -1");
    }
    printf("\n-1");
    for(int i = 2; i <= n; i++){
        if(idx[i] < levels[depth[i]].size()-1) printf(" %d", levels[depth[i]][idx[i]+1]);
        else printf(" -1");
    }
    printf("\n");

    return 0;
}
