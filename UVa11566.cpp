#include <bits/stdc++.h>
using namespace std;

int N, x, T, tea, K, w[202], v[202], m[202][23][2003], money;

int solve(int idx, int taken, int money){
    if(idx == 2*K || taken <= 0 || money <= 0) return 0;
    if(m[idx][taken][money] != -1) return m[idx][taken][money];
    m[idx][taken][money] = solve(idx+1, taken, money);
    if(money >= w[idx]) m[idx][taken][money] = max(m[idx][taken][money], solve(idx+1, taken-1, money-w[idx])+v[idx]);
    return m[idx][taken][money];
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d %d %d %d", &N, &x, &T, &K) != EOF && !(N == 0 && x == 0 && T == 0 && K == 0)){
        N++;
        memset(w, 0, sizeof(w)); memset(v, 0, sizeof(v)); memset(m, -1, sizeof(m));
        for(int i = 0; i < K; i++){
            scanf("%d", &w[2*i]);
            w[2*i+1] = w[2*i];
            int t;
            for(int j = 0; j < N; j++) {
                scanf("%d", &t);
                v[2*i] += t;
            }
            v[2*i+1] = v[2*i];
        }
        int tea = T*N;
        int money = (int) floor( ((x*N)/1.1+1e-6) - tea);
        //cout << money << endl;
        printf("%.02f\n", 1.0*solve(0, 2*N, money)/N);
    }
    return 0;
}
