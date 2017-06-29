#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int N, M, cIdx, low[100010], dfn[100010], cRoot, cnt;

map<int, ll> adj[100010];
bool visited[100010], passArti[100010];
ll memo[100010], rem[100010];
stack<int> stk;
vector<vector<pair<int, ll>>> loop[100010];
vector<ll> loopLen[100010];
set<int> arti[100010];

void tarjans(int u, int pre){
    low[u] = dfn[u] = ++cIdx;
    visited[u] = true;
    stk.push(u);
    for(ii v : adj[u]){
        if(v.first == pre) continue;
        if(!visited[v.first]){
            if(cRoot == v.first) cnt++;
            tarjans(v.first, u);
            if(low[v.first] > dfn[u]) {
                stk.pop();
                arti[u].insert(v.first);
            }else if(low[v.first] < dfn[u])
                low[u] = low[v.first];
            else if(low[v.first] == dfn[u]){
                vector<pair<int, ll>> curr;
                ll len = 0;
                int first = stk.top();
                while(stk.top() != v.first){
                    int c = stk.top(); stk.pop();
                    curr.push_back(make_pair(c, adj[stk.top()][c]));
                    len += adj[stk.top()][c];
                }
                int c = stk.top(); stk.pop();
                curr.push_back(make_pair(c, adj[stk.top()][c]));
                len += adj[stk.top()][c];
                len += adj[stk.top()][first];
                loop[u].push_back(curr);
                loopLen[u].push_back(len);
            }
        }
        if(dfn[v.first] <= low[u]) low[u] = dfn[v.first], arti[u].insert(v.first);
    }
}


void dfs(int u, bool flag){
    visited[u] = true;
    passArti[u] |= flag;
    for(int i = 0; i < (int) loop[u].size(); i++){
        ll cw, ccw = loopLen[u][i];
        cw = 0;
        for(ii v : loop[u][i]){
            cw += v.second;
            ccw -= v.second;
            ll tmp = memo[u]+min(cw, ccw);
            if(memo[v.first] > tmp){
                memo[v.first] = tmp;
                rem[v.first] = max(cw, ccw);
            }else if(memo[v.first] == tmp && rem[v.first] > max(cw, ccw)){
                rem[v.first] = max(cw, ccw);
            }
            if(!visited[v.first]){
                if(arti[u].count(v.first))
                    dfs(v.first, true);
                else
                    dfs(v.first, flag);
            }
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
    //printf("%lld\n", loopLen[1][0]);
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
