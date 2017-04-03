#include <bits/stdc++.h>
#define fori(i, n) for(int i = 0, _n = n; i < n; i++)
using namespace std;

typedef pair<int, int> ii;
int b, s, sum, r[20010], best, start, bs, len, blen;

void solve(){
    best = -99999999; sum = 0; start = 0; bs = 0; len = 0, blen =0 ;
    fori(i, s-1){
        sum += r[i];
        len++;
        if(best < sum){
            best = sum;
            bs = start;
            blen = len;
        }
        if(best == sum && blen < len){
            bs = start; blen = len;
        }
        if(sum < 0){
            start = i+1;
            len = 0;
            sum = 0;
        }
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    scanf("%d", &b);
    for(int B = 1; B <= b; B++){
        scanf("%d", &s);
        fori(i, s-1) scanf("%d", &r[i]);
        solve();
        if(best < 0) printf("Route %d has no nice parts\n", B);
        else printf("The nicest part of route %d is between stops %d and %d\n", B, bs+1, bs+blen+1);
    }
    return 0;
}
