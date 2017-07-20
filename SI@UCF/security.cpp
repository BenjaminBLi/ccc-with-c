#include "bits/stdc++.h"
using namespace std;
typedef vector<int> vi;
typedef pair<long long, int> ii;
typedef long long ll;
ll adj[110][110];
int rooms[110], n, a, b;
bool taken[110];
priority_queue<ii, vector<ii>, greater<ii>> pq;

ll calc(ll x, ll y) {
    ll p1a = x / 100, p1b = y / 100, p2a = x % 100, p2b = y % 100;
    return a * abs(p2a - p2b) + b * abs(p1a - p1b);
}
void process(int u){
    taken[u] = true;
    for(int j = 0; j < n; j++){
        if(j == u) continue;
        ll w = adj[u][j];
        if(!taken[j]) pq.push(ii(w, j));
    }
}

int main(){
    scanf("%d %d %d", &n, &a, &b);
    for(int i = 0; i < n; i++) scanf("%d", rooms+i);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            adj[i][j] = adj[j][i] = calc(rooms[i], rooms[j]);
        }
    }

    process(0);
    ll cost = 0;
    while(pq.size()){
        ii curr = pq.top(); pq.pop();
        int u = curr.second; ll w = curr.first;
        if(!taken[u]) {
            //cout << rooms[u] << ", " << w << endl;
            cost += w, process(u);
        }
    }
    printf("%lld\n", cost);

    return 0;
}
