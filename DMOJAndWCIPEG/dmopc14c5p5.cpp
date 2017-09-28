#include "bits/stdc++.h"
#define ii pair<int, int>
using namespace std;
typedef long long ll;

int N, M, cIdx, low[100010], dfn[100010], cRoot, cnt;

/*
8 10
1 2 1
1 3 1
2 3 1
3 4 1
4 5 1
3 5 1
3 6 1
6 8 1
6 7 1
7 8 1
 */

map<int, ll> adj[100010];
bool visited[100010], passArti[100010];
ll memo[100010], rem[100010];
stack<int> stk;
vector<vector<int>> loop;
vector<ii> stL[100010];
vector<ll> loopLen;
set<int> arti[100010];

void tarjans(int u, int pre){
    //cout << u << ", " << pre << endl;
    low[u] = dfn[u] = ++cIdx;
    visited[u] = true;
    stk.push(u);
    for(ii v : adj[u]){
        if(v.first == pre) continue;
        //cout << "SEARCHING: " << v.first << endl;
        if(!visited[v.first]){
            if(cRoot == v.first) cnt++;
            tarjans(v.first, u);
            if(low[v.first] > dfn[u]) {
                stk.pop();
                arti[u].insert(v.first);
            }else if(low[v.first] < dfn[u])
                low[u] = low[v.first];
            else if(low[v.first] == dfn[u]){
                vector<int> curr;
                ll len = 0;
                int first = stk.top();
                while(stk.top() != v.first){
                    int c = stk.top(); stk.pop();
                    cout << c << endl;
                    curr.push_back(c);
                    len += adj[stk.top()][c];
                }
                int c = stk.top(); stk.pop();
                curr.push_back(c);
                len += adj[stk.top()][c];
                len += adj[stk.top()][first];
                c = stk.top();
                curr.push_back(c);
                loop.push_back(curr);
                int sz = loop.size();
                for(int i = 0; i < (int) curr.size(); i++){
                    stL[curr[i]].push_back(ii(sz-1, i));
                }
                loopLen.push_back(len);
            }
        }
        if(dfn[v.first] <= low[u]) low[u] = dfn[v.first], arti[u].insert(v.first);
    }
}


void dfs(int u, bool flag){
    visited[u] = true;
    passArti[u] |= flag;
    for(int i = 0; i < (int) stL[u].size(); i++){
        int f = stL[u][i].first;
        int s = stL[u][i].second;
        ll cw, ccw = loopLen[f];
        cw = 0;
        int w = u;
        int cnt = 0;
        int sz = loop[f].size();
        for(int j = (s+1)%sz; cnt < sz; cnt++, j++, j %= sz){
            int v = loop[f][j];
            cw += adj[w][v];
            ccw -= adj[w][v];
            ll tmp = memo[u]+min(cw, ccw);
            if(memo[v] > tmp){
                memo[v] = tmp;
                rem[v] = max(cw, ccw);
            }else if(memo[v] == tmp && rem[v] > max(cw, ccw)){
                rem[v] = max(cw, ccw);
            }
            if(!visited[v]){
                if(arti[u].count(v))
                    dfs(v, true);
                else
                    dfs(v, flag);
            }
            w = v;
        }
    }
    for(int v : arti[u]){
        memo[v] = min(memo[v], memo[u] + adj[u][v]);
        passArti[v] |= true;
        if(!visited[v]) dfs(v, true);
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        int u, v; ll w;
        scanf("%d %d %lld", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }
    cRoot = 1, cnt = 0, cIdx = 0;
    tarjans(1, -1);
    memset(visited, false, sizeof(visited));
    fill(memo, memo+N+1, (1LL<<62));
    fill(memo, memo+N+1, (1LL<<62));
    memo[1] = 0;
    dfs(1, false);

    for(int i = 2; i <= N; i++) {
        if(passArti[i]) printf("1 %lld\n", memo[i]);
        else printf("2 %lld\n", memo[i]+rem[i]);
    }

    return 0;
}
