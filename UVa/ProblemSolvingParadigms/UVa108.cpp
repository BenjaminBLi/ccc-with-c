#include <bits/stdc++.h>
#define fori(i, n) for(int i = 0, _n = n; i < _n; i++)
using namespace std;

int N, arr[100][100], x[100], best, curr, rBest, rCurr, sr, sc, er, ec, s, e, locS;

void kadane(int r){
    rBest = -127*100*100; rCurr = 0; s = 0; e = -1;
    fori(i, N){
        rCurr += x[i];
        if(rBest < rCurr){
            rBest = rCurr;
            s = locS; e = i;
        }
        if(rCurr < 0){
            rCurr = 0;
            locS = i+1;
        }
    }
    if(e != -1) return;
    rBest = arr[0]; s = e =0;
    for(int i = 1; i < N; i++){
        if(arr[i] > rBest){
            rBest = arr[i];
            s = e = i;
        }
    }
}

void solve(){
    best = -127*100*100;
    for(int l = 0; l < N; l++){
        memset(x, 0, sizeof(x));
        for(int r = l; r < N; r++){
            fori(i, N) x[i] += arr[r][i];
            kadane(r);
            if(best < rBest){
                best = rBest;
                ec = l;
                sc = r;
                sr = s;
                er = e;
            }
        }
    }
}

int main(){
    //freopen("in.txt", "r", stdin);
    while(scanf("%d", &N) != EOF){
        fori(i, N)fori(j, N) scanf("%d", &arr[i][j]);
        solve();
        printf("%d\n", best);
    }
    return 0;
}
