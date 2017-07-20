#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
digit descent dp?????????????????????

 solve(int idx, int match, int product){
    //check for leading zeroes.
    for(int place = 0; place <= 9; place++){
        if(math == 1 && place > barray[idx]) continue;
        //???
    }
 }

 look for products under mod, since mod is tiny?

 look at the powers and the maximum digits: the max product is ~ 200000


 11121n3
 11161111
 */

long long a, b, blen, barr[20];
int v;
map<ll, int> memo[20][10], seen;

ll p(ll x){
    ll ret = 1;
    for(;x; x >>= 1) ret *= x%10;
    return ret;
}

ll pr(ll x){
    if(seen.count(x)) return seen[x];
    if(x < 10) return x;
    return seen[x] = pr(p(x));
}

ll solve(int idx, int match, ll product){
    //0 = nonzero, not match barr[idx], 1 = no, match barr[idx]...
    if(idx == blen){
        ll t = pr(product);
        return t == v ? 1 : 0;
    }
    for(int p = 0; p <= 9; p++){
        if(match == 1 && p > barr[idx]) continue;
        //????
    }

    return -1;
}

int main(){
    scanf("%lld %lld %d", &a, &b, &v);
    int cnt = 0;
    //???

    return 0;
}
