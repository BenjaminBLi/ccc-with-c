#include "bits/stdc++.h"
#define MAXN 410
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int N, low[MAXN], dfn[MAXN], cIdx = 0, cRoot, cnt, id, hi;
vi adj[MAXN], ids;
map<int, int> meta[MAXN*2];
stack<ii> stk;
vector<vii> edgeSets;
bool isArt[MAXN];

/*
21
1 2
2 3
1 3
1 5
1 6
6 4
1 4
1 8
8 5
8 7
10 9
6 10
5 7
9 6
2 11
3 11
1 11
12 13
14 13
12 14
12 1
0
 */

void dfs(int u, int pre) {
    low[u] = dfn[u] = ++cIdx;
    for (int v : adj[u]) {
        if (pre == v) continue;
        stk.push(ii(u, v));
        if (dfn[v] == 0) {
            if (cRoot == u) cnt++, isArt[cRoot] = cnt > 1;
            dfs(v, u);
            if (low[v] >= dfn[u]) {
                isArt[u] = true;
            }
            if(isArt[u]){
                ii a = ii(u, v);
                vii curr;
                ii c;
                while (stk.top() != a) {
                    c = stk.top(); stk.pop();
                    curr.push_back(c);
                }
                curr.push_back(a);
                stk.pop();
                edgeSets.push_back(curr);
                ids.push_back(id++);
            }

            if(low[u] > low[v]) low[u] = low[v];
        } else if (low[u] > dfn[v]) low[u] = dfn[v];
    }
    dfn[u] = 0x3f3f3f;
}

void root(){
    //??? find some way to root the tree/forest arbitrarily..
}

int main(){
    scanf("%d", &N);
    while(N != 0){
        for(int i = 0; i <= 400; i++) adj[i].clear(), meta[i].clear(), meta[i+MAXN].clear(), dfn[i] = low[i] = 0;
        cnt = 0;
        hi = 0;
        for(int i = 0; i < N; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
            hi = max(hi, max(u, v));
        }
        id = hi+1;
        for(int i = 1; i <= hi; i++) if(dfn[i] == 0) dfs(i, -1);
        for(int i = 0; i < (int)edgeSets.size(); i++){
            for(ii a : edgeSets[i]){
                if(isArt[a.first]) meta[i][a.first] = meta[a.first][i] = 0;
                if(isArt[a.second]) meta[a.second][i] = meta[i][a.second] = 0;
            }
        }
        root();

        scanf("%d", &N);
    }

    return 0;
}