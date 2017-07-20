#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> ii;
typedef pair<ll, int> oii;
typedef vector<ii> vii;

/*
 * remove edges in the cycle and find the diameter for each forest afterwards (store the current best found: deepest and second deepest method
 * afterwards, compress everything into the cycle - use vertex weights for each path, and then count the size of the cycle
 *
 * Max Queue:
 *  4 8 -2 12 11 24 3 -> use a deque to implement it
 *  always looking for the largest element...
 *  aka monoqueue
 *
 *
 */

int n;
vii adj[100010];
ll dist[2][100010];

int solve(int st, int id){
    priority_queue<oii, vector<oii>, greater<oii>> pq;
    for(int i = 0; i <= n; i++) dist[id][i] = (ll) 1e14;
    pq.push(oii(0, st));
    dist[id][st] = 0;

    while(pq.size()){
        int u = pq.top().second; pq.pop();
        for(ii v : adj[u]){
            if(dist[id][v.first] > dist[id][u] + v.second){
                dist[id][v.first] = dist[id][u] + v.second;
                pq.push(ii(dist[id][v.first], v.first));
            }
        }
        //for(int i = 1; i <= n; i++) printf("%lld, ", dist[id][i]); cout << endl;
    }
    ll best = 0;
    int bIdx = -1;
    for(int i = 1; i <= n; i++) if(dist[id][i] > best){
            best = dist[id][i];
            bIdx = i;
        }
    //cout << bIdx << endl;
    return bIdx;
}


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(ii(v, w));
        adj[v].push_back(ii(u, w));
    }
    int b = solve(1, 0);
    //cout << b << endl;
    solve(b, 1);
    ll maxVal = 0;

    //for(int i = 1; i <= n; i++) printf("%lld, ", dist[0][i]); cout << endl; for(int i = 1; i <= n; i++) printf("%lld, ", dist[1][i]); cout << endl;

    for(int i = 1; i <= n; i++){
        if(maxVal < dist[1][i]) maxVal = dist[1][i];
    }
    printf("%lld\n", maxVal);

    return 0;
}
