#include "bits/stdc++.h"
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;


int N, D, white, col[310], l[310], r[310], sum[310][2], black;
int memo[310][310];

void findSum(int u){
    sum[u][col[u]]++;
    if(l[u] != -1){
        findSum(l[u]);
        sum[u][0] += sum[l[u]][0];
        sum[u][1] += sum[l[u]][1];
    }if(r[u] != -1){
        findSum(r[u]);
        sum[u][0] += sum[r[u]][0];
        sum[u][1] += sum[r[u]][1];
    }
}

int dfs(int u, int rem){
    //cout << u << ", " << rem << endl;
    int cdiff = sum[u][1] - sum[u][0];
    if(rem == 0) return 0;
    else if(rem == cdiff) return 1;
    if(memo[u][rem+300] != -1) return memo[u][rem+300];
    int& ans = memo[u][rem+300];
    ans = 0x3f3f3f;
    if(l[u] != -1 && r[u] != -1){
        for(int i = 0; i <= abs(rem); i++){
            int ls = dfs(l[u], rem > 0 ? i : -i);
            int rs = dfs(r[u], rem > 0 ? rem-i : rem+i);
            if(ls != 0x3f3f3f && rs != 0x3f3f3f) ans = min(ans, ls+rs);
        }
    }else if(l[u] != -1){
        int ls = dfs(l[u], rem);
        if(ls != 0x3f3f3f) ans = min(ans, ls);
    }else if(r[u] != -1){
        int rs = dfs(r[u], rem);
        if(rs != 0x3f3f3f) ans =  min(ans, rs);
    }
    return ans;
}

int main(){
    scanf("%d %d", &N, &D);
    white = black = 0;
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    for(int i = 0; i < N; i++){
        int C, id;
        scanf("%d %d %d", &id, col+i, &C);
        if(col[i]) white++;
        else black++;
        if(C) scanf("%d", l+i);
        if(C > 1) scanf("%d", r+i);
    }
    memset(memo, -1, sizeof(memo));
    int cdiff = white-black;
    findSum(0);
    int ans = dfs(0, cdiff-D);
    if(ans == 0x3f3f3f){
        printf("-1\n");
    }else{
        printf("%d\n", ans);
    }
    //cout << sum[4][1] << ", " << sum[4][0] << endl;
    return 0;
}
