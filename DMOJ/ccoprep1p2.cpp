#include "bits/stdc++.h"
#define MAXN 510
#define vi vector<int>
using namespace std;

int N, low[MAXN], dfn[MAXN], cIdx = 0;
vi adj[MAXN];
stack<int> stk;
bool inStk[MAXN];

void tarjan(int u, int pre){
    low[u] = dfn[u] = ++cIdx;
    stk.push(u);
    inStk[u] = true;
    for(int v : adj[u]){
        if(pre == v) continue;
        if(dfn[v] == 0){
            tarjan(v, u);
            if(low[u] > low[v]) low[u] = low[v];
        }else if(inStk[u] && low[u] > dfn[v]) low[u] = dfn[v];
    }
}

int main(){
    for(scanf("%d", &N); N; scanf("%d", &N)){

    }

    return 0;
}