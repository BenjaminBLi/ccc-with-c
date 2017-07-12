#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll res[2][2], orig[2][2], tmp[2][2];
long long a, b, n;
ll MOD = 1000000000LL;

void mA(){
    memset(tmp, 0, sizeof(tmp));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                tmp[i][j] += (res[i][k]*orig[k][j])%MOD;
                tmp[i][j] %= MOD;
            }
        }
    }
    memcpy(res, tmp, sizeof(tmp));
}
void mB(){
    memset(tmp, 0, sizeof(tmp));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                tmp[i][j] += orig[i][k]*orig[k][j];
                tmp[i][j] %= MOD;
            }
        }
    }
    memcpy(orig, tmp, sizeof(tmp));
}

void sqr(ll pow){
    while(pow){
        if(pow&1) mA();
        mB();
        pow >>= 1;
    }
}

int main(){
    scanf("%lld %lld %lld", &a, &b, &n);
    res[0][0] = orig[0][0] = 1;
    res[1][1] = orig[1][1] = 0;
    res[0][1] = orig[0][1] = 1;
    res[1][0] = orig[1][0] = 1;
    if(n-2 > 0) sqr(n-2);
    if(n == 0 )printf("%lld\n", a);
    else if(n == 1) printf("%lld\n", b);
    else printf("%lld\n", ((res[0][1]*1LL*a)%MOD+(res[0][0]*1LL*b)%MOD)%MOD);

return 0;
}
