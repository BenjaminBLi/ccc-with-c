#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N, M, K, memo[1510][10], dist[1510];
bitset adj[1510];


int main(){
    scanf("%d %d %d", &N, &M, &K);
    for(int i =0;i < M; i++){
        int u, v; scanf("%d %d", &u, &v);
        adj[u].set(v, true);
        adj[v].set(u, true);
    }

    return 0;
}
