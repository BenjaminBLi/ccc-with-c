#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int N, nt, t[20], mask, cmask;
long long best;
vi seq;

void solve(int idx){
    if(idx == nt){
        long long sum = 0;
        for(int i = 0; i < nt; i++) if(cmask & (1<<i)) sum += t[i];
        if(best < sum && sum <= N){
            best = sum;
            mask = cmask;
        }
    }else{
        cmask |= (1<<idx);
        solve(idx+1);
        cmask &= ~(1<<idx);
        solve(idx+1);
    }
}

int main(){
    //freopen("in.txt", "r", stdin);
    while(scanf("%d", &N) != EOF){
        scanf("%d", &nt);
        for(int i = 0; i < nt; i++) scanf("%d", &t[i]);
        best = 0;
        mask = 0; cmask = 0;
        solve(0);
        for(int i = 0; i < nt; i++) if(mask & (1<<i)) printf("%d ", t[i]);
        printf("sum:%lld\n", best);
    }
    return 0;
}
