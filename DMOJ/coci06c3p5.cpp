#include "bits/stdc++.h"
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
int N, M, visited[10010], memo[10010];
bool inQ[10010];
map<int, int> adj[10010];

int main(){
    scanf("%d %d", &N, &M);
    for(int i= 0; i < M; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    memset(visited, 0, sizeof(visited));
    bool inf = false, flowed = false;
    queue<ii> q;
    q.push(ii(1, 0));
    visited[1] = 0;
    while(q.size()){
        ii u = q.front(); q.pop();
        if(u.first == 2) continue;

    }
    if(inf) printf("inf\n");
    else {
        if (flowed) printf("%09d", memo[2]);
        else printf("%d\n", memo[2]);
    }

    return 0;
}
