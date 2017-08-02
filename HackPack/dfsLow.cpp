int stk[100], low[100], dfn[100], cRoot;
vector<int> cv;
vector<set<int>> edgeSets;
bool vis[100];

void markEs(int rE) {
    if (!stk[0]) return;
    cnt++;
    set<int> cv;
    while (true){
        int c = stk[stk[0]--];
        cv.insert(id[c].first);
        cv.insert(id[c].second);
        if (stk[0] == 0 || rE == c) break;
    }
    edgeSets.push_back(cv);
    vs.push_back(cv.size());
}

int findO(int u, ii e){
    if(e.first == u) return e.second;
    return e.first;
}

void dfs(int u) {
    low[u] = dfn[u] = ++cIdx;
    int fwdCnt = 0;
    for (int j : adj[u]) {
        int v = findO(u, id[j]);
        if(vis[j]) continue;
        stk[++stk[0]] = j;
        vis[j] = true;
        if (dfn[v] == 0) {
            fwdCnt++;
            dfs(v);
            if(low[u] > low[v]) low[u] = low[v];
            if (cRoot == u ? fwdCnt > 1 : low[v] >= dfn[u]) {
                isArt[u] = true;
                markEs(j);
            }
        } else if (low[u] > dfn[v]) low[u] = dfn[v];
    }
}