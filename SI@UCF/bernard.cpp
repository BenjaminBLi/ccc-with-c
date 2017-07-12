#include <bits/stdc++.h>
using namespace std;

int n, k, arr[100010];
long long memo[100010];

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", arr+i);
    for(int i = 1; i <= n; i++){
        memo[i] = memo[i-1];
        if(i-k >= 0) memo[i] = max(memo[i], memo[i-k-1]+arr[i]);
        else memo[i] = max(memo[i], 1LL*arr[i]);
    }
    printf("%lld\n", memo[n]);
    return 0;
}
