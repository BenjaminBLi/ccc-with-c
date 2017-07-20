#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int s, e, col[110], cSz;
vi adj[110];
bool ok, visited[110], unstable[110];

/*
6 7
3 2
2 5
2 1
4 1
4 0
4 3
5 0
 */

void dfs(int u, int c){
    visited[u] = true;
    cSz++;
    col[u] = c;
    for(int v : adj[u]){
        if(col[v] == c){
            ok = false;
            return;
        }
        if(!visited[v]){
           dfs(v, 1-c);
        }
    }
}

int main(){
    scanf("%d %d", &s, &e);
    for(int i = 0; i < s; i++) col[i] = -1;
    ok = true;

    for(int i = 0; i < e; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int uCnt = 0;

    for(int i = 0; i < s; i++){
        memset(visited, false, sizeof(visited));
        cSz = 0;
        if(col[i] == -1){
            dfs(i, 0);
        }else{
            dfs(i, col[i]);
        }
        if(cSz == 1){
            unstable[i] = true;
            uCnt++;
        }
    }
    int rCnt = 0, bCnt = 0;
    for(int i = 0; i < s; i++){
        if(!unstable[i]) {
            if (col[i] == 1) rCnt++;
            else bCnt++;
        }
    }

    if(rCnt < 2){
        int t = min(2-rCnt, uCnt);
        rCnt += t;
        uCnt -= t;
    }if(bCnt < 2){
        int t = min(2-bCnt, uCnt);
        bCnt += t;
        uCnt -= t;
    }
    //for(int i = 0; i < s; i++) printf("%d, ", col[i]); cout << endl;
    //cout << rCnt << ", " << bCnt << endl;

    if(ok && rCnt > 1 && bCnt > 1) printf("YES\n");
    else printf("NO\n");

    return 0;
}
