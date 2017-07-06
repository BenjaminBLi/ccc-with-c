#include "bits/stdc++.h"
#define vi vector<int>
using namespace std;

int d, c;
vi adj[1010];
bool vis[1010];

int bfs(int st){
    queue<int> q;
    q.push(st);
    vis[st] = true;
    int sz = 0;
    while(q.size()){
        int u = q.front(); q.pop();
        sz++;
        for(int v : adj[u]){
            if(!vis[v]){
                q.push(v);
                vis[v] = true;
            }
        }
    }
    return sz;
}

int main(){
    scanf("%d %d", &d, &c);
    for(int i = 0; i < c; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0;
    for(int i = 1; i <= d; i++){
        if(!vis[i]){
            int c = bfs(i);
            if(c > 1) cnt++;
        }
    }
    printf("%d\n", cnt);

    return 0;
}
