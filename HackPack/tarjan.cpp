
int low[MAXN], dfn[MAXN];
stack<int> scc;
int w;
bool inStk[MAXN];

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