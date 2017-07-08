#include <bits/stdc++.h>
#define MAXN 20010
#define INF 100000000
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
using namespace std;

int N, M, K, Q, hubs[210];

vii adj[MAXN][2];
int dist[210][MAXN][2];
bool visited[MAXN];


void find(int id, int state) {
    priority_queue<ii, vii, greater<ii>> pq;
    memset(visited, false, sizeof(visited));
    pq.push(ii(0, hubs[id]));
    dist[id][hubs[id]][state] = 0;
    while (pq.size()) {
        int u = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (ii nxt : adj[u][state]) {
            ll w = nxt.second;
            int v = nxt.first;
            if (dist[id][v][state] > cost + w) {
                dist[id][v][state] = cost + w;
                pq.push(ii(cost + w, v));
            }
        }
    }
}

int main(){
    freopen("vacationgold.in", "r", stdin); freopen("vacationgold.out", "w", stdout);
    scanf("%d %d %d %d", &N, &M, &K, &Q);
    for(int i = 0; i < M; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][1].push_back(ii(v, w));
        adj[v][0].push_back(ii(u, w));
    }
    for(int i = 0; i < K; i++) {
        scanf("%d", hubs+i);
        for(int j = 0; j < MAXN; j++){
            dist[i][j][0] = INF;
            dist[i][j][1] = INF;
        }
        find(i, 0);
        find(i, 1);
    }

    int cnt = 0;
    ll tot = 0;
    for(int q = 0; q < Q; q++) {
        ll ans = INF;
        int a, b;
        scanf("%d %d", &a, &b);
        for (int i = 0; i < K; i++) {
            if(dist[i][a][0] + dist[i][b][1] < ans) ans = dist[i][a][0] + dist[i][b][1];
        }
        if(ans < INF){
            cnt++;
            tot += ans;
        }
    }
    printf("%d\n%lld\n", cnt, tot);

    return 0;
}
