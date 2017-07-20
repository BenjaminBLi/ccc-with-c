#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int n;
ll arr[100010], maxN, minN;

/*
4
-3 3 7 13
 */

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lld", arr + i);

    minN = arr[n-2]+1;
    maxN = arr[n-1]-1;
    bool ok = true;

    for(int i = n-2; i; i--) {
        ll curr = arr[i];
        ll nMin = max(arr[i - 1] + 1, curr - (maxN - curr));
        ll nMax = min(curr - 1, curr - (minN - curr));
        if (nMin <= arr[i - 1] || nMax >= curr || nMax < nMin) {
            ok = false;
            break;
        }
        minN = nMin;
        maxN = nMax;
    }
    if(ok){
        ll finMin = arr[0] - (maxN - arr[0]);
        ll finMax = arr[0] - (minN - arr[0]);
        printf("%lld %lld\n", finMin, finMax);
    }else printf("-1\n");

    return 0;
}
