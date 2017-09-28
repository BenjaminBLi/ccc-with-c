#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define f first
#define s second
using namespace std;

int N, M, scCnt = 0, cIdx = 0, gold[500010], low[500010], dfn[500010], p[500010], w;
int tot[500010];
ii memo[4][500010];
int MOD = 1000000007;
vi adj[500010];
set<int> dag[500010];
bool inStk[500010];
stack<int> scc;

void tarjan(int u) {
    low[u] = dfn[u] = ++cIdx;
    scc.push(u);
    inStk[u] = true;
    for (int v : adj[u]) {
        if (dfn[v] == 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inStk[v]) low[u] = min(low[u], dfn[v]);
    }

    if (low[u] == dfn[u]) {
        while (scc.top() != u) {
            w = scc.top();
            p[w] = scCnt;
            inStk[w] = false;
            scc.pop();
            tot[scCnt] += gold[w];
        }
        w = scc.top();
        p[w] = scCnt;
        tot[scCnt] += gold[w];
        inStk[w] = false;
        scc.pop();
        scCnt++;
    }
}

void compress(){
    for(int i = 1; i <= N; i++){
        for(int v : adj[i]) if(p[i] != p[v]) dag[p[i]].insert(p[v]);
        adj[i].clear();
    }
}

ii solve(int u, bool take){
    if(u == p[N]){
        if(take)
            return ii(tot[u], 1);
        return ii(0, 1);
    }if(memo[take][u] != ii(-1, -1))
        return memo[take][u];

    ii ans = ii(-1000000000, 0), tmp;
    for(int v : dag[u]){
        if(take){
            tmp = solve(v, false);
            tmp.f += tot[u];
            if(tmp.f > ans.f){
                ans = tmp;
            }else if(tmp.f == ans.f){
                ans.s += tmp.s;
                ans.s %= MOD;
            }
        }
        tmp = solve(v, true);
        if(tmp.f > ans.f)
            ans = tmp;
        else if(tmp.f == ans.f) {
            ans.s += tmp.s;
            ans.s %= MOD;
        }
    }
    memo[take][u] = ans;
    return ans;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) memo[0][i] = memo[1][i] = ii(-1, -1);
    for(int i = 1; i <= N; i++) scanf("%d", gold+i);
    int u, v;
    for(int i = 0; i < M; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }

    tarjan(1);
    compress();

    ii fin = solve(p[1], true);
    printf("%d %d\n", fin.f, fin.s);
    return 0;
}
