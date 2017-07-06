#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define f first
#define s second
using namespace std;

int N, M, scCnt = 0, cIdx = 0, gold[500010], low[500010], dfn[500010], p[500010];
int tot[500010], memo[2][500010], cnt[2][500010];
int MOD = 1000000007;
vi adj[500010];
set<int> dag[500010];
bool visited[500010], inStk[500010];
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

    int w;
    if (low[u] == dfn[u]) {
        while (scc.top() != u) {
            w = scc.top();
            p[w] = scCnt;
            inStk[w] = false;
            scc.pop();
        }
        w = scc.top();
        p[w] = scCnt;
        inStk[w] = false;
        scc.pop();
        scCnt++;
    }
}

void compress(){
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(q.size()){
        int u = q.front(); q.pop();
        tot[p[u]] += gold[u];
        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                if(p[u] != p[v]) dag[p[u]].insert(p[v]);
            }
        }
    }
}

ii solve(int u, bool take){
    if(u == p[N]){
        return ii(take ? tot[u] : 0, 1);
    }if(memo[take][u] != -1)
        return ii(memo[take][u], cnt[take][u]);

    ii ans = ii(-1000000000LL, 0), tmp;
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
        if(tmp.f > ans.f) ans = tmp;
        else if(tmp.f == ans.f) ans.s += tmp.s, ans.s %= MOD;
    }
    memo[take][u] = ans.f;
    cnt[take][u] = ans.s;
    return ans;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) scanf("%d", gold+i);
    for(int i = 0; i < M; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }

    tarjan(1);
    compress();
    memset(memo, -1, sizeof(memo));
    memset(cnt, -1, sizeof(cnt));

    ii fin = solve(p[1], true);
    printf("%d %d\n", fin.f, fin.s);
    return 0;
}
