#include "bits/stdc++.h"
#define ll long long
using namespace std;

int N, W;
ll w[1010];

int main(){
    scanf("%d %d", &N, &W);
    for(int i = 0; i < N; i++) scanf("%lld", w+i);
    sort(w, w+N);
    ll sum = W;
    int idx = 0;
    while(sum > 0 && idx < N){
        if(sum - w[idx] < 0) break;
        sum -= w[idx];
        idx++;
    }
    printf("%d\n", idx);
    return 0;
}
