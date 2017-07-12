#include "bits/stdc++.h"
#define ll long long
using namespace std;

/*
5 100
1
2
3
4
10
 */

ll t;
ll m[100010];
int c;

int main(){
    scanf("%d %lld", &c, &t);
    for(int i = 0; i < c; i++) scanf("%lld", m+i);
    sort(m, m+c);
    bool flag = false;
    for(int i = 1; i < c; i++){
        ll diff = m[i]-m[i-1];
        if(diff*i <= t) {
            t -= diff*i;
        }else{
            m[i-1] += t/i;
            printf("%lld\n", m[i-1]);
            flag = true;
            break;
        }
    }
    if(!flag) printf("%lld\n", m[c-1]+t/c);


    return 0;
}
