#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define sf second.first
#define ss second.second
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;

int D, N, M, dist[2][500010];

vii adj[2][500010];
queue<iii> extra;

int main(){
    scanf("%d %d", &N, &M);
    for(int i =0;i < M; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[0][u].pb({v, w});
        adj[1][v].pb({u, w});
    }
    scanf("%d", &D);
    for(int i =0;i < D; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        extra.push(iii(u, ii(v, w)));
    }
    priority_queue<ii, vii, greater<ii>> pq;
    memset(dist, 0x3f3f3f, sizeof(dist));
    //cout << 0x3f3f3f << endl;
    dist[0][1] = 0;
    dist[1][N] = 0;
    for(int i =0;i < 2; i++){
        if(!i) pq.push({0, 1});
        else pq.push({0, N});
        for(;pq.size();){
            int u = pq.top().s; pq.pop();
            for(ii v : adj[i][u]){
                if(dist[i][v.f] > dist[i][u]+v.s){
                    dist[i][v.f] = dist[i][u]+v.s;
                    pq.push({dist[i][v.f], v.f});
                }
            }
        }
    }


    int ans = dist[0][N];
    while (extra.size()) {
        auto curr = extra.front();
        extra.pop();
        ans = min(ans, dist[0][curr.f] + curr.ss + dist[1][curr.sf]);
    }
    if(ans == 1061109567) printf("-1\n");
    else printf("%d\n", ans);



    return 0;
}