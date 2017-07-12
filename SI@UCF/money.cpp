#include <bits/stdc++.h>
using namespace std;

int n, coin[20], memo[20][1000010], t;

int solve(int cIdx, int val){
    if(val == 0) return 1;
    else if(val < 0) return 0;
    else if(cIdx == n && val > 0) return 0;
    if(memo[cIdx][val] != -1) return memo[cIdx][val];
    memo[cIdx][val] =  solve(cIdx+1, val) + solve(cIdx+1, val-coin[cIdx]);
    return memo[cIdx][val];
}

int main(){
    scanf("%d %d", &n, &t);

    for(int i = 0; i < n; i++) scanf("%d", coin+i);
    memset(memo, -1, sizeof(memo));
    cout << solve(0, t) << endl;

    return 0;
}
