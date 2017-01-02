#include <bits/stdc++.h>
using namespace std;

int n, curr[16];
bool prime[33];

void genP(){
    memset(prime, true, sizeof(prime));
    prime[0] = false; prime[1] = false;
    for(int i = 2; i*i <= 32; i++){
        if(prime[i]){
            for(int j = i*i; j < 33; j+=i) prime[j] = false;
        }
    }
}

void solve(int idx, int mask){
    if(idx == n && prime[curr[0]+curr[n-1]] && mask == (1<<n)-1){
        printf("%d", curr[0]);
        for(int i = 1; i < n; i++){
            printf(" %d", curr[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 0; i < n; i++){
        if((mask&(1<<i)) == 0){
            curr[idx] = i+1;
            if(prime[curr[idx]+curr[idx-1]]) solve(idx+1, mask|(1<<i));
        }
    }
}

int main(){
    genP();
    int cnt = 1;
    scanf("%d", &n);
    while(true){
        printf("Case %d:\n", cnt++);
        curr[0] = 1;
        solve(1, 1);
        if(scanf("%d", &n) != EOF) printf("\n");
        else break;
    }
    return 0;
}

