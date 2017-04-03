#include <bits/stdc++.h>
using namespace std;

//dp[s][l-1], dp[l][r-1], dp[r][e];
//if(dp[s][l-1] == dp[r][e] && (l==r || dp[l][r] ???) update stuff

int memo[400][400], rice[400], N, l2, r2, best;

bool valid(int st, int en){
    if(st == en) return true;
    else return memo[st][en] != -1;
}

int calc(int st, int en){
    if(st == en) return rice[st];
    else return memo[st][en];
}

bool f2(int s, int e){
    for(int l = s+1; l <= e; l++){
        int fe = l-1;
        if(!valid(s, fe)) continue;
        if(!valid(l, e)) continue;
        int fc = calc(s, fe);
        int lc = calc(l, e);
        if(fc != lc) continue;
        memo[s][e] = fc+lc;
        return true;
    }
    return false;
}

void f3(int fs, int le){
    for(int ms = fs+1; ms < le; ms++){
        int fe = ms-1;
        if(!valid(fs, fe)) continue;
        int fc = calc(fs, fe);
        for(int ls = ms+1; ls <= le; ls++){
            int me = ls-1;
            if(!valid(ms, me)) continue;
            if(!valid(ls, le)) continue;
            int lc = calc(ls, le);
            if(fc != lc) continue;
            int mc = calc(ms, me);
            memo[fs][le] = fc + mc + lc;
            return;
        }
    }
}

int main(){
    scanf("%d", &N); memset(memo, -1, sizeof(memo));
    for(int i = 0; i < N; i++) scanf("%d", &rice[i]);
    for(int sz = 2; sz <= N; sz++){
        int mS = N-sz+1;
        for(int fs=0; fs<mS; fs++){
            int le = fs+sz-1;
            bool found = f2(fs, le);
            if(found) continue;
            if(sz>2) f3(fs, le);
        }
    }
    int best = 0;
    for(int s = 0; s < N; s++) for(int e = s; e < N; e++) best = max(best, calc(s, e));
    cout << best << endl;
}
