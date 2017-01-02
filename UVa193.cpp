#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> adj;
vi sol;
int m, n, k, a, b, best;
bool visited[100], col[100];

void dfs(int node){
    if(node == n){
        int nB = 0;
        for(int i = 0; i < n; i++) if(col[i]) nB++;
        if(nB > best){
            best = nB;
            sol.clear();
            for(int i = 0; i < n; i++) if(col[i]) sol.push_back(i+1);
        }
        return;
    }
    bool y = false;
    for(int n : adj[node]) y |= col[n];
    if(!y){
        col[node] = true;
        dfs(node+1);
        col[node] = false;
    }
    dfs(node+1);
}

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d", &m);
    for(;m--;){
        memset(visited, false, sizeof(visited)); memset(col, false, sizeof(visited));
        scanf("%d %d", &n, &k);
        adj.assign(n, vi());
        best = 0; sol.clear();
        for(int i = 0; i < k; i++){
            scanf("%d %d", &a, &b);
            a--; b--;
            adj[a].push_back(b); adj[b].push_back(a);
        }
        dfs(0);
        printf("%d\n", best);
        for(int i = 0; i < (int) sol.size(); i++){
            printf("%d", sol[i]);
            if(i < sol.size()-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
