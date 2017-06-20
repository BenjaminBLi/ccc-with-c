#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;

int N, A, B, Y[2010];
long long sums[2010];

bool comp(int a, int b){
    return a > b;
}

int main(){
    scanf("%d %d %d", &N, &A, &B);
    for(int i = 0; i < N; i++) scanf("%d", Y+i);
    sort(Y, Y+N, comp);
    ll ans = 1LL<<60;
    for(int g = A; g <= B; g++) {

        for (int i = 0; i < N; i++) {
            int minChanged = 63;
            int idx = 0;
            memset(sums, 0, sizeof(sums));
            for(int j = 0; j < g; j++){
                int bts = __builtin_popcount(sums[j]);
                if(__builtin_popcount(sums[j]+Y[i])-bts <= minChanged || sums[j] == 0){
                    idx = j;
                    minChanged = __builtin_popcount(sums[j]+Y[i])-bts;
                }
            }
            printf("%d: %d\n", idx, Y[i]);
            sums[idx] += Y[i];
        }
        ll c = 0;
        for (int i = 0; i < g; i++) {
            printf("%lld, ", sums[i]);
            c |= sums[i];
        }
        cout << endl;
        ans = min(ans, c);
    }
    printf("%lld\n", ans);

    return 0;
}
