#include "bits/stdc++.h"
#define vi vector<int>
#define ii pair<int, int>
using namespace std;

int N, memo[200010][4];
vi adj[200010], tree[200010];
bool visited[200010];

void setRoot() {
    queue<ii> q;
    q.push(ii(1, -1));
    visited[1] = true;
    while (q.size()) {
        int u = q.front().first;
        int prev = q.front().second;
        q.pop();
        if(prev != -1) tree[prev].push_back(u);
        for (int v : adj[u]) {
            if (!visited[v]) {
                q.push(ii(v, u));
                visited[v] = true;
            }
        }
    }
}

int solve(int u, int flag) {
    if (tree[u].size() == 0) {
        return flag;
    }
    if (memo[u][flag] != -1) return memo[u][flag];
    int ans = 100000;
    if (flag == 1) {
        int sF = 1, sI = 1;
        for (int v : tree[u]) {
            sF += solve(v, 0);
            sI += solve(v, 1);
        }
        ans = min(ans, sF);
        for (int v : tree[u]) {
            int sEx = 0;
            for (int w : tree[v]) {
                sEx += solve(w, 0);
            }
            ans = min(ans, sI - solve(v, 1) + sEx);
        }
    } else {
        int sF = 1, sI = 0;
        for (int v : tree[u]) {
            sF += solve(v, 0);
            sI += solve(v, 1);
        }
        ans = min(ans, min(sF, sI));
    }
    memo[u][flag] = ans;
    return memo[u][flag];
}

int main(){
    scanf("%d", &N);
    for(int i = 1; i < N; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    setRoot();
    memset(memo, -1, sizeof(memo));
    printf("%d\n", solve(1, 1));

    return 0;
}