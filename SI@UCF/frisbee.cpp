#include "bits/stdc++.h"
#define s second
#define f first
using namespace std;
typedef pair<int, int> ii;

/*
14 12
7 5
8 9
9 2
10 11
11 3
7 12
13 14
13 1
14 4
13 6
13 10
4 8
 */

int N, M, col[10010];
ii curr;
vector<int> pairs;
map<int, int> adj[10010], memo[100010];
bool ok;

int opt(int a, int b){
    if(abs(a) > abs(b)) return b;
    return a;
}

int solve(int idx, int sum){
    if(memo[idx].count(sum)) return memo[idx][sum];
    if(idx == (int) pairs.size()){
        return sum;
    }
    int best = 0x3f3f3f;
    best = opt(best, solve(idx+1, sum + pairs[idx]));
    best = opt(best, solve(idx+1, abs(sum - pairs[idx])));
    memo[idx][sum] = best;
    return best;
}

void dfs(int u){
    if(col[u]) curr.first++;
    else curr.second++;
    for(ii v : adj[u]){
        if(col[v.first] == col[u]) ok = false;
        if(col[v.f] == -1) {
            col[v.f] = 1 - col[u];
            dfs(v.f);
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    ok = true;
    for(int i = 0; i < N; i++) adj[i].clear();
    for(int i = 0; i < M; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    memset(col, -1, sizeof(col));
    for(int i = 1; i <= N; i++) {
        if (col[i] == -1) {
            curr = ii(0, 0);
            col[i] = 0;
            dfs(i);
            pairs.push_back(abs(curr.first-curr.second));
        }
    }

    if(!ok) {
        printf("Impossible\n");
    }else{
        int bDiff = solve(0, 0);
        //cout << bDiff << endl;
        int a = N/2-bDiff/2;
        int b = N/2+bDiff/2;
        if(N&1) b++;
        printf("%d %d\n", a, b);
    }

    return 0;
}
