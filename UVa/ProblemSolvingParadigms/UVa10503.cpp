#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int n, m, st[20], en[20], s1, e1, s2, e2;
ii s, e;
bool used[20];
bool solve(int idx, int prev){
    if(idx == n){
        return prev == s2;
    }
    for(int i = 0; i < m; i++){
        if(used[i]) continue;
        if(st[i] == prev || en[i] == prev){
            used[i] = true;
            bool yes;
            if(st[i] == prev) yes = solve(idx+1, en[i]);
            else yes = solve(idx+1, st[i]);
            if(yes) return true;
            used[i] = false;
        }
    }
    return false;
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d", &n) && n){
        scanf("%d", &m);
        memset(used, false, sizeof(used));
        scanf("%d %d", &s1, &e1); scanf("%d %d", &s2, &e2);
        for(int i = 0; i < m; i++) scanf("%d %d", &st[i], &en[i]);


        if(solve(0, e1)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
