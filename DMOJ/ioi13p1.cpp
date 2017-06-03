#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int ansV, D, p[100010], w[100010];
vii adj[100010];
bool totV[100010];

void dfs(int u, int pre, int cSz){
    //printf("%d %d: %d\n", u, pre, cSz);
    p[u] = pre;
    totV[u] = true;
    if(D <= cSz){
        ansV = u;
        D = cSz;
        //cout << "YES: " << D << ", " << ansV << endl;
    }
    for(ii v : adj[u]){
        if(v.first == pre) continue;
        if(!totV[v.first]) w[v.first] = v.second, dfs(v.first, u, cSz+v.second);
    }
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]){
    for(int i = 0; i < M; i++){
        int u = A[i], v = B[i], w = T[i];
        adj[u].push_back(ii(v, w));
        adj[v].push_back(ii(u, w));
    }

    int r1 = 0, r2 = 0, r3 = 0, d, R, maxD = 0;
    memset(p, -1, sizeof(p));
    for(int i = 0; i < N; i++){
        if(p[i] != -1) continue;
        ansV = i, D = 0;
        memset(totV, false, sizeof(totV));
        dfs(i, -2, 0);
        memset(totV, false, sizeof(totV));
        //cout << ansV << ", ";
        dfs(ansV, -2, 0);
        maxD = max(maxD, D);
        //cout << ansV << endl;
        R = D, d = 0;
        for(int u = ansV; p[u] != -2; u = p[u]){
           // cout << u  << endl;
            R = min(R, max(D-d, d));
            d += w[u];
        }
        //cout << endl;
        if(r1 < R) r2 = r1, r1 = R;
        else if(r2 < R) r3 = r2, r2 = R;
        else if(r3 < R) r3 = R;
    }
    //printf("%d %d %d\n", r1, r2, r3);
    return max(maxD, max(r1+r2+L, r2+r3+2*L));
}

int main(){
    int a[] = {0, 8, 2, 5, 5, 1, 1, 10};
    int b[] =  {8, 2, 7, 11, 1, 3, 9, 6};
    int t[] = {4, 2, 4, 3, 7, 1, 5, 3};
    printf("%d\n", travelTime(12, 8, 2, a, b, t));
}