#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;

/*
5 5
0 3 3
1 3 5
2 2 2
1 2 4
2 3 1

 */


int N, C[100010], idx[100010], p[100010];
ll L[100010], M, sum[100010], best = 0;
vi adj[100010];
priority_queue<int> pq[100010];
void cleanse(int n){
    int id = idx[n];
    while(sum[n] > M && pq[id].size()){
        sum[n] -= pq[id].top();
        pq[id].pop();
    }
}
void merge(int u, int p){
    if(u == p) return;
    int idU = idx[u];
    int idP = idx[p];
    sum[p] += sum[u];
    if(pq[idU].size() > pq[idP].size()){
        while(pq[idP].size()){
            pq[idU].push(pq[idP].top());
            pq[idP].pop();
        }
        idx[u] = idP;
        idx[p] = idU;
    }else{
        while(pq[idU].size()){
            pq[idP].push(pq[idU].top());
            pq[idU].pop();
        }
    }
    cleanse(p);
}


void dfs(int u, int p){
    pq[idx[u]].push(C[u]), sum[u] += C[u];
    for(int v : adj[u]) dfs(v, u);
    cleanse(u);
    ll tmp = pq[idx[u]].size();
    tmp *= L[u];
    //cout << u << ": " << pq[idx[u]].size() << ", sum: " << sum[u] << ", " << tmp << endl;
    best = max(best, tmp);
    merge(u, p);
}

int main(){
    scanf("%d %lld", &N, &M);
    int root = 0;
    for(int i = 1; i <= N; i++){
        scanf("%d %d %lld", p+i, C+i, L+i);
        adj[p[i]].push_back(i);
        if(p[i] == 0) root = i;
        idx[i] = i;
        sum[i] = 0;
    }
    dfs(root, 0);

    printf("%lld\n", best);

    return 0;
}