#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int n;
ll arr[100010], l[100010], r[100010];

/*
15
 -7 4 6 6 -12 9 10 11 -20 -4 10 5 0 0 0
 */


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", arr+i);
    }
    ll curr = 0, best = 0;
    for(int i = 0; i < n; i++) {
        curr += arr[i];
        if (best < curr) best = curr;
        if (curr < 0) curr = 0;
        l[i] = best;
    }
    curr = best = 0;
    for(int i = n-1; i >= 0; i--){
        curr += arr[i];
        if(best < curr) best = curr;
        if(curr < 0) curr = 0;
        r[i] = best;
    }

    ll ans = max(0LL, l[n-1]);

    for(int i = 0; i < n-1; i++) ans = max(ans, l[i] + r[i+1]);

    printf("%lld\n", ans);

    return 0;
}
