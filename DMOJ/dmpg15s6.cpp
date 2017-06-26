#include "bits/stdc++.h"
using namespace std;
typedef pair<int, double> ii;
typedef pair<int, int> pii;
typedef vector<ii> vii;

map<string, int> id;
int N, M, ids = 0, vCnt[510];
double dist[510], val;
bool inQ[510], hasCycle;
string a, b;
vii adj[510];

/*
3 4
APPLES
ORANGE
GRAPE
ORANGE APPLES 2
APPLES ORANGE 0.5
APPLES GRAPE 1
GRAPE ORANGE 1
 */

void spfa(int st){
    fill(dist, dist+N, 1e100);
    fill(vCnt, vCnt+N, 0);
    queue<int> q;
    hasCycle = false;
    q.push(st); dist[st] = 0; inQ[st] = true, vCnt[st]++;
    while(q.size()){
        int u = q.front(); q.pop();
        if(vCnt[u] > N-1){
            hasCycle = true;
            break;
        }
        vCnt[u]++; inQ[u] = false;
        for(ii v : adj[u]){
            if(dist[v.first] > dist[u] + v.second+1e-9){
                dist[v.first]  = dist[u] + v.second+1e-9;
                if(!inQ[v.first]) q.push(v.first), inQ[v.first] = true, vCnt[v.first]++;
            }
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> a;
        id[a] = ids++;
    }
    for(int i = 0; i < M; i++){
        cin >> a >> b >> val;
        adj[id[a]].push_back(ii(id[b], -log10(val)));
    }
    spfa(id["APPLES"]);
    if(hasCycle) cout << "YA\n";
    else cout << "NAW\n";

    return 0;
}
