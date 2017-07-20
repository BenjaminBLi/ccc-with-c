#include "bits/stdc++.h"
using namespace std;
typedef pair<long long, int> ii;

int n, k;
long long x[100010];
ii sums[100010];

/*
10 4
14 12 18 19 13 12 14 14 10 20
 */

bool comp(ii a, ii b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%lld", x+i);
        x[i] += x[i-1];
        //cout << x[i] << endl;
    }
    //cout << (n-k+1) << endl;
    for(int i = k; i <= n; i++){
        long long c = x[i]-x[i-k];
        sums[i-k] = ii(c, i-k+1);
        //cout << c << endl;
    }
    sort(sums, sums+n-k+1, comp);
    for(int i = k; i <= n; i++) printf("%d ", sums[i-k].second);
    printf("\n");
    return 0;
}
