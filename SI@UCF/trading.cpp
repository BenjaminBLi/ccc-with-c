#include "bits/stdc++.h"
using namespace std;

int n, a, b, val[210];
long long sA, sB;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", val+i);
    sA = 0;
    for(int i = 0; i < n; i++){
        int cnt;
        scanf("%d", &cnt);
        sA += 1LL*cnt*val[i];
    }
    scanf("%d", &n);
    for(int i =0 ; i < n; i++) scanf("%d", val+i);
    for(int i = 0; i < n; i++){
        int cnt;
        scanf("%d", &cnt);
        sB += 1LL*cnt*val[i];
    }
    printf("%lld %lld\n", sA, sB);

    return 0;
}
